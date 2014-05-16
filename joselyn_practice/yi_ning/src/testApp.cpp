#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate( 60 );
	ofBackground(20);
	ofDisableArbTex();
	ofEnableAlphaBlending();
	ofBlendMode(OF_BLENDMODE_DISABLED);
    
    glShadeModel(GL_SMOOTH);
	quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    
	vidGrabber.initGrabber(640, 480);
	flowSolver.setup(320, 240, 0.5, 3, 10, 1, 7, 1.5, false, true );
	bGetBackground = true;
	bDrawGui = false;
	bDrawBtn = false;
    
	//---light
    ofSetSmoothLighting(true);
    pointLight.setAmbientColor( ofFloatColor(.1, .08, .07) );
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f) );
    pointLight2.setDiffuseColor( ofFloatColor( 180.f/255.f, 120.f/255.f, 135.f/255.f ) );
    pointLight2.setSpecularColor(ofFloatColor(.9f, .9f, .9f) );
    pointLight.setPosition( (ofGetWidth()*.7), ofGetHeight()/3, 500  );
    pointLight2.setPosition( -ofGetWidth()*.4, ofGetHeight(), 500);
    
    //---material
    material.setShininess( 100 );
	material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    //---shader
    shader.load("shaders/displace.vert", "shaders/displace.frag");
    
    //---texture Images
    fbo.allocate( 640, 480 );
    texFbo.allocate( 640, 480 );
    img.allocate( 640, 480, OF_IMAGE_COLOR_ALPHA );
    smallVidImg.allocate( 30, 40, OF_IMAGE_COLOR_ALPHA );
    texImg.allocate( 640, 480, OF_IMAGE_COLOR_ALPHA );
    
    //---texImg.loadImage("bg.jpg");
    perlinImg.loadImage("perlin5.png");
    yPos = -480;
    
    //---GUI
    gui.setup();
    gui.add(thres.setup("threshold", 30, 0, 100, 300, 10));
    //gui.add(blur.setup("blur", 10, 0, 25, 300, 10));
    
    //---CV image
    vidGrayImg.allocate( 640, 480 );
    bgImg.allocate( 640, 480 );
    diffImg.allocate( 640, 480 );
    
    //---OSC
    mSender.setup( "localhost", 55688 );
    
    //---left buttons
    for( int i = 0; i < 12; i++ ){
        ofRectangle rect;
        rect.set( 0, i*40, 40, 40 );
        leftBtns.push_back( rect );
        bool left = false;
        bLeftBtnTrue.push_back( left );
    }
}
//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
        flowSolver.update(vidGrabber);
		vidColorImg.setFromPixels(vidGrabber.getPixelsRef());
		vidGrayImg = vidColorImg;
		vidGrayImg.mirror(false, true);
        if(bGetBackground){
            bgImg = vidGrayImg;
            bGetBackground = false;
        }
        diffImg.absDiff( bgImg, vidGrayImg );
        diffImg.threshold( thres );
        //diffImg.blur( blur*2 + 1 );
    }
    
    //---Perlin Noise movement
    yPos += 10;
    if( yPos > 0 ){
        yPos = -480;
    }
    
    //---blob tracker
    contourFinder.findContours(diffImg, (640 * 480)*0.01, (640*480)*0.9, 4, false);
    for(int i=0; i<contourFinder.nBlobs; i++){
        ofxCvBlob& blob = contourFinder.blobs[i];
        for(int j=0; j<blob.pts.size(); j++){
            //blob.pts[j].x= ofMap(blob.pts[j].x, 0, 640, 0, 640);
            //blob.pts[j].y = ofMap(blob.pts[j].y, 0, 480, 0, 480);
            for( int k = 0; k < leftBtns.size(); k ++ ){
                if( leftBtns[k].inside(blob.pts[j]) ){
                    bLeftBtnTrue[k] = true;
                }
            }
        }
    }
    for(int i = 0; i < bLeftBtnTrue.size(); i++ ){
        if( bLeftBtnTrue[i] ){
            ofxOscMessage m;
            m.setAddress("/btn" );
            m.addIntArg(i);
            mSender.sendMessage( m );
            if( !bDrawBtn ){
                bLeftBtnTrue[i] = false;
            }
        }
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));
    
    //---bump map
    fbo.begin();
    ofClear( 255, 255, 255, 0 );
    ofPushMatrix();{
        ofTranslate( 640, 0 );
        ofScale( -1, 1 );
        perlinImg.draw(0,yPos,640,960);
        flowSolver.draw(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3, 1); //1 = circle, 0 = line, 3 = colored
    }ofPopMatrix();
    fbo.end();
    fbo.readToPixels(pix);
    img.setFromPixels(pix);
    img.draw(0,0);
    
    //---texture to be shown
    texFbo.begin();
    ofClear( 255, 255, 255, 0 );
    ofPushMatrix();{
        ofTranslate( 640, 0 );
        ofScale( -1, 1 );
        vidGrabber.draw(0,0);
        flowSolver.drawColored(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3);
    }ofPopMatrix();
    texFbo.end();
    texFbo.readToPixels(pix);
    texImg.setFromPixels(pix);
    texImg.draw(0,0);
    
    ofBackground(100);
    
    ofEnableDepthTest();
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    glEnable(GL_TEXTURE_2D);
	material.begin();
    
	shader.begin();
	shader.setUniformTexture("colormap", texImg, 1);
    shader.setUniformTexture("bumpmap", img , 2);
    shader.setUniform1i("maxHeight",ofGetHeight()*0.2);
    shader.setUniform3f("CAMERA_POSITION", 1000, -100,300);
    
    ofPushMatrix();{
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        //ofRotateY(360*sinf(float(ofGetFrameNum())/500.0f));
        ofRotate(-90,1,0,0);
        gluSphere(quadric, ofGetWindowHeight()*0.18, 400, 200);
    }ofPopMatrix();
    shader.end();
    material.end();
    glDisable(GL_TEXTURE_2D);
    ofDisableLighting();
    ofDisableDepthTest();
    
    //---Draw GUI
    if( bDrawGui ){
        gui.draw();
        bgImg.draw( 10, 100, 240, 180 );
        diffImg.draw( 10, 290, 240, 180 );
    }
    
    //--Draw Blob tracker debug
    if( bDrawBtn ){
        //---left side buttons
        ofPushStyle();{
            ofSetColor( 0,0,255 );
            ofNoFill();
            ofRect(0,0,640,480);
            for( int i = 0; i < 12; i++ ){
                ofRect( 0, i*40, 40, 40 );
            }
        }ofPopStyle();
        
        for(int i=0; i<contourFinder.nBlobs; i++){
            ofPushStyle();{
                ofSetColor(255,0,0);
                ofNoFill();
                ofxCvBlob& blob = contourFinder.blobs[i];
                ofBeginShape();
                for(int j=0; j<blob.pts.size(); j++){
                    ofVertex(blob.pts[j]);
                    if(myRect.inside(blob.pts[j])){
                        ofPushStyle();
                        ofSetColor(0,0,255);
                        ofRect(500,500,300,300);
                        ofPopStyle();
                    }
                }
                ofEndShape();
            }ofPopStyle();
        }
        for(int i = 0; i < bLeftBtnTrue.size(); i++ ){
            if( bLeftBtnTrue[i] ){
                ofPushStyle();
                ofSetColor(0, 0, 255);
                ofRect( 0, i*40, 40, 40 );
                ofPopStyle();
                bLeftBtnTrue[i] = false;
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    switch (key) {
		case 'p':
			bDrawGui = !bDrawGui;
			break;
        case ' ':
            bGetBackground = true;
            break;
        case 'm':
            ofSetFullscreen(true);
            break;
        case 'n':
            ofSetFullscreen(false);
            break;
        case 'b':
            bDrawBtn = !bDrawBtn;
            break;
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
