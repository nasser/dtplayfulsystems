#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(20,20,20);
    ofSetColor(255,255,255);
    ofEnableAntiAliasing();
    moving = 0.3;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

float testApp::xCoordinateOnLine(float t, float x1, float x2) {
    t = ofClamp(t, 0, 1);
    return (x2 - x1) * t + x1;
}

float testApp::yCoordinateOnLine(float t, float y1, float y2) {
    t = ofClamp(t, 0, 1);

    return (y2 - y1) * t + y1;
}

ofPoint testApp::pointOnLine(float t, ofPoint p1, ofPoint p2) {
    t = ofClamp(t, 0, 1);

    return (p2 - p1) * t + p1;
}

//--------------------------------------------------------------
void testApp::draw(){


/* PERLIN NOISE EXAMPLE
for (int i = 0; i < 1280 * 0.5; i++) {
    for (int j = 0; j < 720 * 0.5; j++) {
        //ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        //ofSetColor(255 * ofNoise(255, i, j), 255 * ofNoise(255, i, j), 255 * ofNoise(255, i, j)); // ofNoise returns value of 0 and 1
        ofSetColor(255 * ofNoise(255, i, j, mouseX*.01), 255 * ofNoise(255, i, j, mouseX*.01), 255 * ofNoise(255, i, j, mouseX*.01));
        //ofRect(i*10,j*10,10,10);
        ofRect(i * 5, j * 5, 5, 5);
    }
    }

    // convert x number of min/max from 0/1 to different min/max
    // x*(max-min) + min

*/

    /*LINEAR INTERPOLATION EXAMPLE

    //ofClamp(limit this number, min this number, max this number);  limits the number
    float mouseX01 = ofClamp(float(mouseX) / ofGetWidth(), 0, 1);

    //float circleX = ofMap(mouseX, 0, ofGetWidth(), 50, 350, true); //simplified on the next line with created function
    //float circleY = ofMap(mouseX, 0, ofGetWidth(), 450, 300 + sin(ofGetElapsedTimef() * 5) * 20, true);

    //float circleX = xCoordinateOnLine(mouseX01, 50, 350);
    //float circleY = yCoordinateOnLine(mouseX01, 100, 300);

    ofPoint circlePoint = pointOnLine(mouseX01, ofPoint(50, 100), ofPoint(350,300));

    //ofCircle(circleX, circleY, 5);
    ofCircle(circlePoint, 5);
    */



    ofPoint from, to, circleCenter, circleCenter1, from1, to1;
    from1.set(mouseX,mouseY);
    //to1.set(ofGetWidth() - 10, 10);
    to1.set(clickSpot);



    //from.set(50,                ofGetHeight()/2);

    from = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from1, to1);
    to.set  (ofGetWidth() - 50, ofGetHeight()/2);

    circleCenter = pointOnLine(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1), from, to);
    //circleCenter = from.getInterpolated(to, ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1)); //oF built in function to do the same thing

    // draw circle
    ofCircle(circleCenter, 10);

    //draw control points and line to help visualize what is happening
    ofCircle(from, 2);
    ofCircle(from1, 2);
    ofCircle(to, 2);
    ofCircle(to1, 2);
    ofLine(from, to);
    ofLine(from1, to1);


    float t = ofGetElapsedTimef() - int(ofGetElapsedTimef());
    t = sqrt(1 - powf(1 - t, 2)); //golan levans easing functions

    circleCenter1 = pointOnLine(t, from, to);
    //ofCircle(circleCenter1, 5);

    //circleCenter2 = pointOnLine(t, )

    //circleCenter1 = pointOnLine(t, from, to);
    ofCircle(circleCenter1, 5);


    cout<< "t is " << t << endl;

    // WEEK 5 HOMEWORK -- GREY CIRCLE GOLAN LEVINS EASE-IN INTERPOLATION

    if (testRun.x < ofGetWidth()) {
        testRun.x += 1;
    } else {
        testRun.x = 0;
    }
        testRunPercent.x = testRun.x / ofGetWidth();


        moving += 0.05;

        if (moving >= 0.9){
            moving = 0.0;
        }

        int finishArc = mouseX;

        testRun.y = sqrt( powf(finishArc * moving, 2) - powf(testRun.x - moving * finishArc, 2)       );




        ofSetColor(50,50,50,200);
        ofCircle(testRun.x, testRun.y, 5);
        cout << "testRun x = " << testRun.x << "  testRun y = " << testRun.y << "moving = "<<moving<< endl;
        ofSetColor(255,255,255, 100);
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
    clickSpot.set(mouseX,mouseY);
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
