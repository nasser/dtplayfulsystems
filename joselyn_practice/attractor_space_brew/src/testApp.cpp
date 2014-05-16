#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    movie.loadMovie("geode.mov");
    
    movie.play();
    
ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs OF";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("sliderX", "range");  // just typing "boolean" also works
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);

}

//--------------------------------------------------------------
void testApp::update(){
    movie.update();


}

//--------------------------------------------------------------
void testApp::draw(){
    
    void testApp::draw(){
        
        //for geode
        movie.draw(-500, -1000, 2000, 2000);
        
        
        int n = 100000;
        
        //a = 1.40, b = 1.56, c = 1.40, d = -6.56
        float a = 100.01;
        float b = -2.53;
        float c = 1.61  + sin(scaledVol);//+ sin(ofGetElapsedTimef()/2);
        float d = -0.33 ;
        
        
        //
        //    float a = 1.4;
        //    //sin(ofGetElapsedTimef()*scaledVol);
        //    float b = 1.56;
        //    float c = 1.40 + +sin(ofGetElapsedTimef()*scaledVol);
        //
        //    float d = -6.56;
        
        float x0, y0, x1, y1;
        x0 = y0 = x1 = y1 = 0;
        
        
        
        //for ----geodes--------------
        
        ofTranslate(ofGetWidth()/2*2, ofGetHeight()/4*4);
        ofScale(500, 200, 200);
        
        //ofMatrix
        
        for (int i=0; i<n; i++) {
            x1 = y0 - sin(x0)*(b*x0-c)*0.5;
            y1 = sin(c * x0) - cos(d * y0);
            
            ofFill();
            ofLine(x1, y1, x1+0.01, y1);
            
            x0 = x1;
            y0 = y1;
        }


}

    
    //--------------------------------------------------------------
    void testApp::onMessage( Spacebrew::Message & m ){
        if ( m.name == "sliderX" ){
            //int sliderXValue = m.valueRange();
            sliderXValue = ofToInt(m.value) / 1024.0 * 500;
            cout << sliderXValue << endl;
            
            }
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
