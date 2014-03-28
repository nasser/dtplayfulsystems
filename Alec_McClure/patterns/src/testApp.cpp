#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(20,20,20);
    lineMultiplier = 0.9;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //lineMultiplier = ((float(mouseX) / ofGetWidth()) + (float(mouseY) / ofGetHeight())) * 10;
    lineMultiplier = (float(mouseX) / ofGetWidth()) * 10;
    //ofLine(0,lineMultiplier * 100,500,0,100,100);//ofGetWidth() / 2,ofGetHeight() / 2);
    //ofLine(100,100,200,200);//,300,300);
    //ofLine(100,100,0,200,200,400); //x1,y1,z1,x2,y2,z2


    for (float i = 0.0; i < 10000; i += 100){
       // ofLine(0,(lineMultiplier * ofGetHeight()) * i, (lineMultiplier * ofGetWidth()) * i, 0);
        //ofLine(0,ofGetHeight(), ofGetWidth(), 0);
        //ofLine(0,650,1200,0);


    //for (float i = 0.0; i < ofGetHeight(); i += 1.0) {
        //ofLine(0,0,0, float(mouseX*i), ofGetHeight() - float(mouseY), 500); //draws lines out from the top left
        //ofLine(0,ofGetHeight()*i, 0, float(mouseX), float(mouseY), 500);


//        ofLine(0,(ofGetHeight()*lineMultiplier) + i, (ofGetWidth()*lineMultiplier) - i, ofGetHeight()); //lines from left side to bottom
//        ofLine(ofGetWidth(), (ofGetHeight()*lineMultiplier) - i, (ofGetWidth()*lineMultiplier) + i, 0); //lines from right side to top


        strokeChange = (i/10000)*255;
        //ofSetColor(ofColor(190, 89, 100));




        ofSetColor(82, 203, 255);



        lineI = lineMultiplier * i;

        ofLine(ofGetWidth() - lineI, 0,0, ofGetWidth(), ofGetHeight() - lineI,-(5 * lineI)); // in 3 dimensions
        ofLine(ofGetWidth() - lineI, ofGetHeight(),0, ofGetWidth(), lineI,0 -(5 * lineI)); // in 3 dimensions
        ofLine(ofGetWidth() - lineI, 0, ofGetWidth(), ofGetHeight() - lineI); // in 2 dimensions
        ofLine(ofGetWidth() - lineI, ofGetHeight(), ofGetWidth(), lineI); // in 2 dimensions







        cout << lineMultiplier << endl;

}
    for (float i = 0; i < 500; i += 1){ // 12.8, 25.13, 37.63, etc.
        lineI = lineMultiplier * i;
        //ofLine((ofGetWidth()*lineMultiplier) + lineI, 0,0, (ofGetHeight()*lineMultiplier) - lineI); //lines from top to left
        //ofLine(ofGetWidth(), (ofGetHeight()*lineMultiplier) - i, (ofGetWidth()*lineMultiplier) + i, 0); //lines from right side to top

        ofSetColor(33,188,255);

        //ofSetColor(33,188,255);


        ofLine(lineI, 0, 0, ofGetHeight() - lineI); //2d
        ofLine(lineI, ofGetHeight(), 0,lineI);
        ofLine(lineI, 0, 0, 0, ofGetHeight() - lineI, -5 * lineI); //3d
        ofLine(lineI, ofGetHeight(), 0, 0,lineI, -5 * lineI);






}


    /*myfont.loadFont("arial.ttf", mouseX/14);
    ofSetColor(255,255,255);
    myfont.drawString("LINEZ!!!", (ofGetWidth()/2) - 100, ofGetHeight()-100);*/




    /* SPOTLIGHT STUFF

    for (float i = 0; i <= 360; i+= 4){
        //float x = float(mouseX);//ofGetWidth() / 2;
        //float y = float(mouseY);//ofGetHeight() / 2;

        ofPoint outer; //create object called outer from class ofPoint
        outer.x = (cos(ofDegToRad(i)) * 100) + mouseClickX;
        outer.y = (sin(ofDegToRad(i)) * 100) + mouseClickY;

        float x = (cos(ofDegToRad(i)) * 20) + float(mouseX);// ofGetWidth()) * 360;
        float y = (sin(ofDegToRad(i)) * 20) + float(mouseY);// + sin(ofDegToRad(i)*5);

        float outerX = (cos(ofDegToRad(i)) * 100) + mouseClickX; //cos(angle) * length + x location of center
        float outerY = (sin(ofDegToRad(i)) * 100) + mouseClickY; //cos(angle) * length + y location of center

        ofLine(x,y, outerX,outerY);

}
        END SPOTLIGHT STUFF*/


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

    mouseClickX = float(mouseX);
    mouseClickY = float(mouseY);
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
