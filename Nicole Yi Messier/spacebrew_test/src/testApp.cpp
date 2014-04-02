#include "testApp.h"

//--------------------------------------------------------------
ofMesh testApp::pixelManipulate(ofImage imageA, ofMesh meshA, float intensityThreshold, ofPoint sketchDepth){
    
    imageA.resize(200, 200);
    
    //create mesh with points as the primitive
    //meshA.setMode(OF_PRIMITIVE_POINTS);
    
    //create a mesh with lines
    meshA.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    int w = imageA.getWidth();
    int h = imageA.getHeight();
    
    //loop through each pixel in the image using image width & height
    for (int x=0; x<w; x++){
        for(int y=0; y<h; y++){
            
            //create the color object at that pixel
            ofColor c = imageA.getColor(x, y);
            
            //check the intensity of the pixel's color
            float intensity = c.getLightness();
            
            //if the intensity exceeds the threshold, create a vertex at the location of the pixel
            //& color it with the pixel's color
            if (intensity >= intensityThreshold){
                
                //pushes brighter colors in the positive z direction
                //pushes whiter colors in the negative z direction
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -sketchDepth.x, sketchDepth.y);
                
                //the image is now 1/4 the size of the OF window, so multiply
                //the pixel location by 4 so that the mesh covers the OF window
                ofVec3f pos(4*x, 4*y, z);
                meshA.addVertex(pos);
                meshA.addColor(c);
            }
        }
    }
    
    //print the number of vertices in the mesh
    //cout << meshA.getNumVertices() << endl;
    
    
    return meshA;
}

//--------------------------------------------------------------
ofPoint testApp::pointOnLine(ofPoint p1, ofPoint p2, float t){
    ofClamp(t, 0, 1);
    
    return((p2 - p1)*t +p1);
}

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs OF";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("sliderX", "range");  // just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
    //load image
    imageOne.loadImage("flower.png");
    imageTwo.loadImage("philly2.png");
    
    int sliderXValue;
    
    //-----------movie------------
    myPlayer.loadMovie("groundswell.mp4");
    myPlayer.play();
    
}

//--------------------------------------------------------------
void testApp::update(){
      myPlayer.update(); // get all the new frames
}

//--------------------------------------------------------------
void testApp::draw(){
    myPlayer.draw(0, 0, 800, 800);
    
    //ofColor centerColor = ofColor(85, 78, 68);
    //ofColor edgeColor(0, 0, 0);
    //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    
    ofMesh meshOne;
    ofMesh meshTwo;
    ofPoint from1, to1, from2, to2, from3, to3, from4, to4, meshPoint;
    from1.set(0,0);
    to1.set(ofGetWidth(), 0);
    from2.set(0, ofGetWindowHeight());
    to2.set(ofGetWidth(), ofGetHeight());
    float t = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, 1);
    
    //meshPoint = pointOnLine(from1, to1, t);
    meshPoint.set(sliderXValue*20, sliderXValue*20);
    
    //3D view
    //left click to drag to rotate
    //right click to drag to zoom
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    meshOne = pixelManipulate(imageOne, meshPassOne,  50,  meshPoint);
    meshOne.draw();
    
    meshTwo = pixelManipulate(imageTwo, meshPassTwo,  25,  meshPoint);
    meshTwo.draw();
    
    ofPopMatrix();
    easyCam.end();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
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

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    if ( m.name == "sliderX" ){
        //int sliderXValue = m.valueRange();
        sliderXValue = ofToInt(m.value) / 1024.0 * 500;
        cout << sliderXValue << endl;

    }
}

