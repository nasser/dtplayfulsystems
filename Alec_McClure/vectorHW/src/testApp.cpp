#include "testApp.h"




/*

HOMEWORK NOTES:

This was a dumb use of vectors.  I could have used a regular variable, but I had fun.

*/


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(25);

    float howMany = 100;

    for(float i = 0; i < howMany; i++){

        points.push_back(ofPoint(ofGetWidth()/howMany * i, ofGetHeight()/2));

    }

}




//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<points.size(); i++) {

        /*
        points[i].y = ofGetHeight()/2 + sin(i + ofGetElapsedTimef()) * 300; //last number is the pixel height multiplier
        points[i].x *= 1.008;
        */

        float temp = i/10;
        points[i].x = ofRandom(points[i].x- i , points[i].x + i);
        points[i].y = ofRandom(points[i].y - i, points[i].y + i);

    }

}

//--------------------------------------------------------------
void testApp::draw(){


    //////vector of points

    ofSetColor(150);
    for (int i=0; i<points.size()-1; i++) {
        ofLine(points[i], points[i+1]);
        ofLine(points[i].x + 80, points[i].y, points[i+1].x, points[i+1].y);//


    }



    ///// end vector


    int n = 1000;

    float a = 0 + sin(ofGetElapsedTimef());
    float b = -2.3;
    float c = 2.4;
    float d = -2.1;

    float x0, x1;// = ofGetWidth()/2;
    float y0, y1;// = ofGetHeight()/2;
    x0 = y0 = x1 = y1 = 0;

    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofScale(150, 150, 150);
    float rectSize = 10;


    for (int i=0; i<n; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);


        /*
        x1 = (x1 *150) + ofGetWidth()/2;
        y1 = (y1 *150) + ofGetHeight()/2;
        x0 = (x0 *150) + ofGetWidth()/2;
        y0 = (x0 *150) + ofGetHeight()/2;

*/
        //x0 = x0 * 100 + ofGetWidth()/2; //why dont these work???
        //x1 = x1 * 100 +  ofGetWidth()/2;
        //y0 = y0 * 100 +  ofGetHeight()/2;
        //y1 = y1 * 100 +  ofGetHeight()/2;



        ofSetLineWidth(2);
        float rectMult = 200;//(float(i) / float(n)) * 200;
        rects.push_back(ofRectangle(x1 * rectMult + ofGetWidth()/2, y1 * rectMult + ofGetHeight()/2, rectSize, rectSize)); //had to hard code it :(

        ofSetColor(100,100,255,(float(i) / float(n)) * 200);
        ofRect(rects[rects.size()-1]); //lolz dumb

        cout << "Drawing at " << rects[rects.size()-1] << endl;

        ofSetColor(255, 255, 255, 150);
        ofSetLineWidth(1);

        float x3 = x1 * 2;
        float y3 = y1 * 2;
        float x4 = x1;
        float y4 = y1;

        float xAdd = 0;//mouseX;//ofGetWidth()/2;
        float yAdd = 0;//mouseY;//ofGetHeight()/2;
        ofPoint target;
        target.x = mouseX;
        target.y = mouseY;

        ofPoint myPoint;
        myPoint.set(x4,y4);
        myPoint = target.interpolate(myPoint, 0.1);
        //interpolate(

        ofLine(myPoint.x * 100 + xAdd, myPoint.y * 100 + yAdd, myPoint.x *100+ 3 + xAdd, myPoint.y *100 + yAdd); // the plus number is an offset since were using lines (cant show points)



        x0 = x1;
        y0 = y1;
    }


    /*
    n *= 50;
    for (int i=0; i<n; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);

        ofSetColor(255);
        ofLine(x1, y1, x1+0.001 * 150, y1); // the plus number is an offset since were using lines (cant show points)

        x0 = x1;
        y0 = y1;



    }

    */




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
