#include "testApp.h"

//--------------------------------------------------------------

//TYPO VERTICES BASED ON JEFF CROUSE EXAMPLE

void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(10);
    ofSetDataPathRoot("../Resources/data/");
    
//    svg.load("form5.svg");

    // Load the font
    string filename = "Verdana.ttf";
    int fontSize = 260;
    bool bAntiAliased = true;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 0.3; // uses ofPolyline::simplify
//THIS SHOWS THE LINES AND ELLIPSES
    font.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    
    
    // Get the bounding box of the text
    text = "A";
    bb = font.getStringBoundingBox(text, 1, 1);
    
    //R
    myTime = sin(ofGetElapsedTimef() );
    myScale = myTime;

    //R
    verdana200.loadFont("verdana.ttf", 260, true, true);
	verdana200.setLineHeight(18.0f);
	verdana200.setLetterSpacing(1.037);
    
    //R
    amount = 0.1;
    tam = 0;
    tamX = 0;
    tamY = 0;

    
    myColor.r = ofRandom(250);
    myColor.g = ofRandom(200);
    myColor.b = ofRandom(150);

}

//--------------------------------------------------------------
void testApp::update(){
    myTime = fabs( sin(ofGetElapsedTimef()) );

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10);
    
    int nVerts = 0;
    
    
    ofNoFill();
    ofRectangle rect = verdana200.getStringBoundingBox(text, 0,0);

    //Size of typo rects boundaries
    float typoPosX = rect.width/2;
    float typoPosY = rect.height/2;

    //Size & Position typoshapes
    
    
    //R
    tam = ofLerp(tam, 100, amount);
    tamX = ofLerp(tamX, typoPosX, amount);
    tamY = ofLerp(tamY, typoPosY, amount);

    
    ofPushMatrix();
//    {
    
//        ofTranslate((ofGetWidth()/2.0)-(bb.getWidth()/2.0), (ofGetHeight()/2.0)+(bb.height/2.0));
          ofTranslate(    ofGetWidth()/2.0, ofGetHeight()/2.0 );
//        ofRect(rect.x, rect.y, rect.width, rect.height);
        

        //FIRST ELEMENTS
        ofSetColor(myColor);
        ofFill();
        ofCircle(rect.x, rect.y + typoPosY*2, rect.height/2 + tam);

        
    
        // Create a bunch of Letter objects
        vector<ofPath> letterPaths = font.getStringAsPoints(text);
        for(int i=0; i<letterPaths.size(); i++)
        {
            vector<ofPolyline> lines = letterPaths[i].getOutline();
            for(int j=0; j<lines.size(); j++)
            {
                ofPolyline line = lines[j];
                line.simplify();
                
                ofBeginShape();
                for(int k=0; k<line.size(); k++)
                {
                    ofSetColor(200, 150);
//                    ofVertex(line[k].x + 0 + typoPosY + ofRandom(200), line[k].y + typoPosY + ofRandom(200) );z
                    ofVertex(line[k].x  - typoPosX, line[k].y  + typoPosY );

                    
                    
                    ofSetColor(myColor/2, 200);
                    ofNoFill();
                    ofCircle(line[k].x - typoPosX, line[k].y + typoPosY, tam/2);
                    nVerts++;
                }
                ofEndShape(true);
            }
        }
    //}
    ofSetColor(255, 180);
    verdana200.drawString(text,  0 - typoPosX, 0 + typoPosY);

    ofPopMatrix();
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//	testChar = testFont.getCharacterAsPoints(key);
	text = key;
    
    tam = 5;
    tamX = ofRandom(100);
    tamY = ofRandom(100);

    myColor.r = ofRandom(250);
    myColor.g = ofRandom(200);
    myColor.b = ofRandom(50);

    
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
