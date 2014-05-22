#include "testApp.h"


/*
 
 Image Sequence Example:
 In this example we are going to load a sequence of images from a folder.
 We know that the images are in order and the we saved them out at 24fps.
 the goal is to play them back at 24fps independent of the fps of the app.
 You can toggle the sequence to be independent of the app fps.
 
 Topics:
 - ofDirectory
 - ofImage
 - timing
 
 gif from: http://probertson.livejournal.com/32350.html
 
 */


//--------------------------------------------------------------
void testApp:: drawPointOnLine(ofPoint p1, ofPoint p2, float t){
    t = ofClamp(t, 0, 1);
    ofPoint circleCenter = p1.getInterpolated(p2, t);
    
    ofCircle(circleCenter, 2);
    //ofLine(p1, p2);
    
    //ofSetColor(255, 255, 255, 50);
    ofCircle(circleCenter, 4);
    
    // ofCircle(p1, 3);
    // ofCircle(p2, 3);
}

//--------------------------------------------------------------
void testApp::setup() {
    
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    //ofEnableAlphaBlending();
    ofBackground(0);
    
    brush.loadImage("brush2.png");
    brush.resize(450, 450);
    hand.loadImage("hand.jpg"); //dstImage
    
    maskFbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
#else
    if(ofGetGLProgrammableRenderer()){
    	string vertex = "#version 150\n\
    	\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelViewMatrix;\n\
    	uniform mat4 modelViewProjectionMatrix;\n\
    	\n\
    	\n\
    	in vec4  position;\n\
    	in vec2  texcoord;\n\
    	\n\
    	out vec2 texCoordVarying;\n\
    	\n\
    	void main()\n\
    	{\n\
        texCoordVarying = texcoord;\
        gl_Position = modelViewProjectionMatrix * position;\n\
    	}";
		string fragment = "#version 150\n\
		\n\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
		\
        out vec4 fragColor;\n\
		void main (void){\
		vec2 pos = texCoordVarying;\
		\
		vec3 src = texture(tex0, pos).rgb;\
		float mask = texture(maskTex, pos).r;\
		\
		fragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
		shader.bindDefaults();
		shader.linkProgram();
    }else{
		string shaderProgram = "#version 120\n \
		#extension GL_ARB_texture_rectangle : enable\n \
		\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
		\
		void main (void){\
		vec2 pos = gl_TexCoord[0].st;\
		\
		vec3 src = texture2DRect(tex0, pos).rgb;\
		float mask = texture2DRect(maskTex, pos).r;\
		\
		gl_FragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
		shader.linkProgram();
    }
#endif
    
    
    // Let's clear the FBO's
    // otherwise it will bring some junk with it from the memory
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    bBrushDown = true;
    
    //this is where the image sequence begins
    // read the directory for the images
    ofDirectory dir;
    
    int nFiles = dir.listDir("smokeyHeart2");
    if(nFiles) {
        
        for(int i=0; i<dir.numFiles(); i++) {
            
            // add the image to the vector
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().loadImage(filePath);
        }
    }
    // this toggle will tell the sequence
    // be be indepent of the app fps
    bFrameIndependent = true;
    
    // this will set the speed to play
    // the animation back we set the
    // default to 24fps
    sequenceFPS = 24;
    
    // set the app fps
    appFPS = 60;
    ofSetFrameRate(appFPS);
    
    
    
    a1.set(329, 321); // windy part
    a2.set(445, 157); //
    
    
    b1.set(555, 227); //windy connect
    b2.set(445, 157); //connect to heart
    
    c1.set(450, 261); //windy part
    c2.set(445, 157);
    
    d1.set(450, 261); //windy part
    d2.set(555, 227);
    
    e1.set(450, 261); //windy part
    e2.set(328, 323);
    
    f1.set(450, 261);//windy part
    f2.set(548, 310);
    
    g1.set(543, 381);//windy part
    g2.set(548, 310);
    
    h1.set(555, 227);//windy part
    h2.set(548, 310);
    
    j1.set(548, 310);
    j2.set(493, 319);
    
    k1.set(407, 319);
    k2.set(330, 323);
    
    l1.set(534, 462);
    l2.set(623, 375);
    
    m1.set(536, 460);
    m2.set(528, 537);
    
    n1.set(329, 324);
    n2.set(350, 347);
    
    o1.set(527, 536);
    o2.set(485, 516);
    
    q1.set(621, 537);
    q2.set(622, 377);
    
    r1.set(621, 537);
    r2.set(535, 460);
    
    s1.set(621, 537);
    s2.set(527, 536);
    
    t1.set(623, 378);
    t2.set(571, 332);
    
    
    tspsReceiver.connect( 12000 );
    ofxAddTSPSListeners(this);


}

//--------------------------------------------------------------
void testApp::update() {
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();

    ofPushMatrix();
    ofTranslate(ofGetWidth()/4, 0);
    maskFbo.begin();
    if (bBrushDown){
        for (int i=0; i<people.size(); i++){
            ofPoint centroid = people[i]->centroid;
            centroid.x *= ofGetWidth();
            centroid.y *= ofGetHeight();

            brush.draw(centroid.x - 200, centroid.y - 250);

//        brush.draw(mouseX - ofGetWidth()/3, mouseY - 120);
    }
    }
    maskFbo.end();
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    
    
    shader.begin();
    shader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1 );
    
    //DRAWING WITHIN THE SHADER WILL REVEAL WHAT'S UNDER THE FLASHLIGHT
    
    drawHeartGif();
    shader.end();
    fbo.end();
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::draw() {
    ofSetColor(255,255, 255); //do not change
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();

    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4, 0);
    hand.draw(0, -10); //top image
    
    fbo.draw(0,0);
    maskFbo.begin();
    for (int i=0; i<people.size(); i++){
        ofPoint centroid = people[i]->centroid;
        centroid.x *= ofGetWidth();
        centroid.y *= ofGetHeight();

    brush.draw(centroid.x - 200, centroid.y - 200);
    }
    // rgbaFboFloat.draw(0,0);
    ofClear(0, 0, 0, 255);
    maskFbo.end();
    ofPopMatrix();
    
    ofNoFill();
   // triangulation.draw();
    
    //DRAW CIRCLES
    
    ofFill();
    
    ofSetColor(255, 255, 255, 100);
    drawCircleSwarm();
    ofSetColor(255, 255, 255);
    
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if(key == OF_KEY_UP)      appFPS ++;
    if(key == OF_KEY_DOWN)    appFPS --;
    if(key == OF_KEY_LEFT)    sequenceFPS --;
    if(key == OF_KEY_RIGHT)   sequenceFPS ++;
    if(key == 't')            bFrameIndependent = !bFrameIndependent;
    
    // check for less than zero...
    sequenceFPS = MAX(sequenceFPS, 1);
    appFPS      = MAX(appFPS, 1);
    
    ofSetFrameRate(appFPS);
}

//--------------------------------------------------------------
void testApp::drawHeartGif(){
    
    int frameIndex = 0;
    
    if(bFrameIndependent) {
        // calculate the frame index based on the app time
        // and the desired sequence fps. then mod to wrap
        frameIndex = (int)(ofGetElapsedTimef() * sequenceFPS) % images.size();
    }
    else {
        // set the frame index based on the app frame
        // count. then mod to wrap.
        frameIndex = ofGetFrameNum() % images.size();
    }
    
    // draw the image sequence at the new frame count
    ofSetColor(255);
    images[frameIndex].draw(0, 0);
}

//-----------------------------------------------------------
void testApp::drawCircleSwarm(){
    
    //  ofSetColor(255, 255, 255, 50);
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(a1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef()*2)), a2, cos(ofGetElapsedTimef()*2+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(b1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), b2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(c1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), c2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(d1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), d2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(e1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), e2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(f1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), f2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(g1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), g2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(h1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), h2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(j1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), j2, cos(ofGetElapsedTimef()+.85*i));
    }
    //
    for (int i = 0; i <5; i++){
        drawPointOnLine(k1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), k2, cos(ofGetElapsedTimef()+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(l1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), l2, cos(ofGetElapsedTimef()+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(m1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), m2, cos(ofGetElapsedTimef()+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(n1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), n2, cos(ofGetElapsedTimef()+.85*i));
    }
    for (int i = 0; i <5; i++){
        drawPointOnLine(o1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef())), o2, cos(ofGetElapsedTimef()+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(q1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef()*2)), q2, cos(ofGetElapsedTimef()*2+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(r1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef()*2)), r2, cos(ofGetElapsedTimef()*2+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(s1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef()*2)), s2, cos(ofGetElapsedTimef()*2+.85*i));
    }
    
    for (int i = 0; i <5; i++){
        drawPointOnLine(t1 + ofPoint(i*2*cos(ofGetElapsedTimef()), 2*i*sin(ofGetElapsedTimef()*2)), t2, cos(ofGetElapsedTimef()*2+.85*i));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    //
    //    triangulation.addPoint(ofPoint(300 + ofRandom(0, 200), 100+(ofRandom(0, 200))));
    //    triangulation.triangulate();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    cout << "mouse x is: " << mouseX << " mouse y is: " << mouseY << endl;
    
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
//--------------------------------------------------------------
void testApp::onPersonEntered(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "New person!");
}

//--------------------------------------------------------------
void testApp::onPersonUpdated(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person updated!");
}

//--------------------------------------------------------------
void testApp::onPersonWillLeave(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person left!");
}
