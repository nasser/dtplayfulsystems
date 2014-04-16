#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    star.loadImage("fire.jpg");
    star.resize(200, 160);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 150.0;
    int w = star.getWidth();
    int h = star.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = star.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -500, 500);
                ofVec3f pos(x*5, y*5, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                
                 offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            
            }
        }
    }
    ofSetFrameRate(60);
            float connectionDistance = 30;
            int numVerts = mesh.getNumVertices();
            for (int a=0; a<numVerts; a++) {
                ofVec3f verta = mesh.getVertex(a);
                for (int b=a+1; b<numVerts; b++) {
                    ofVec3f vertb = mesh.getVertex(b);
                    float distance = verta.distance(vertb);
                    if (distance <= connectionDistance) {
                        mesh.addIndex(a);
                        mesh.addIndex(b);
                    }
                }
            }
    
    
    
    
    
  //  vector <ofPoint> mouseData;
}

//ofPoint testApp::mouseData(float x, float y){
//    x=mouseX;
//    y=mouseY;
//}


//--------------------------------------------------------------
void testApp::update(){
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 2;
        ofVec3f timeOffsets = offsets[i];
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
}    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
   // star.draw(0,0);
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
