#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    theColor.set(0,0,0);
    test1 = 20;
    test2 = 10;
    test0 = 20;
    lnx = 0;
    lny = 80;
    count=20;
    count2= 3;
    lnx1 =20;
    test3 = 100;
    lyn2 = 30;
    lnx3 = 1000;
    lnx33 = 200;
    
}

//--------------------------------------------------------------
void testApp::update(){
    theColor.r+=1;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*1, i*test1,test2);
    }
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*2, i*test1,test2);
    }
    test2+=3;
    if(test2>ofGetHeight()){
        test2=0;
//        test2=ofGetHeight()-3;
    }
    
    test0+=1;
    if(test0>ofGetHeight()){
        test0=0;
    }

    ln+=1;
    if(ln>ofGetHeight()){
        ln=0;
    }
//
//        for (int i=count2; i<40; i++) {
//            ofLine(i* lnx, lny, i*test1,test2);
//        
//    }
    
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*3, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*4, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*5, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*6, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*7, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*8, i*test1,test2);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*9, i*test1,test2);
    }
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*10, i*test1,test2);
    }
    
    for (int i=count; i<40; i++) {
        ofLine(i* lnx, lny*10, i*test1,test2);
    }
//    
//    
//    for (int i=count; i<150; i++) {
//        ofLine(i* lyn2, lny*1, i*test2,test2);
//    }
//    
//    for (int i=count; i<150; i++) {
//        ofLine(i* lyn2, lny*2, i*test2,test2);
//    }
//    
//    for (int i=count; i<150; i++) {
//        ofLine(i* lyn2, lny*3, i*test2,test2);
//    }
//    
//    for (int i=count; i<150; i++) {
//        ofLine(i* lyn2, lny*4, i*test2,test2);
//    }
//    for (int i=count; i<150; i++) {
//        ofLine(i* lyn2, lny*5, i*test2,test2);
//    }
    for (int i=count; i<10; i++) {
        ofLine(lyn2, lny*6, i*test2,test2);
    }
    
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0-50,ln);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0,ln+30);
    }
    
    
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+50,ln+60);
    }
    
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+100,ln+90);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+150,ln+120);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+200,ln+150);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+250,ln+180);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+300,ln+210);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+350,ln+240);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+400,ln+270);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+450,ln+300);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+500,ln+330);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+550,ln+360);
    }

    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+600,ln+390);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+650,ln+420);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+700,ln+450);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+750,ln+480);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+800,ln+510);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+850,ln+540);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+900,ln+570);
    }
    for (int i=count; i<40; i++) {
        ofLine(i *lnx33, lny*9, test0+950,ln+600);
    }
    
//    test2+=2;
//        if(test2>ofGetHeight()){
//             test2=0;
    

    
    
//    for (int i=count; i<40; i++) {
//        ofLine(i *lnx3, lny*9, test1,test2+300);
//    }

    
//    
//    for (int i=count; i<60; i++) {
//        ofLine(lnx*9,i*  lny, test1,10*test2);
//    }
//    
//    for (int i=count; i<40; i++) {
//        ofLine(lnx*9,i*  lny, test1*20,i*test2);
//    }
//    
//    for (int i=count; i<40; i++) {
//        ofLine(lnx*9,i*  lny, test1*80,test2);
 //   }
//    
//    for (int i=count; i<40; i++) {
//        ofLine(i* lnx, lny, test1, i*test2);
//    }
    
//    for (int i=count; i<40; i++) {
//        ofLine(lnx*8,i*lny, test1*8, i*test3);
//    }
    
//    test2+=2;
//    if(test2>ofGetHeight()){
//        // test2=0;
//    }
//    
//    
//    for (int i=count; i<50; i++) {
//        ofLine(i* lnx1, lny, i*test1,test2);
//        
//    }
//    
//    test2+=10;
//    if(test2>ofGetHeight()){
//        // test2=0;
//    }
//    
//    
//    for (int i=count; i<50; i++) {
//        ofLine(i* lnx1+10, lny, i*test1,test2);
//        
//        
//        
//        
//    }
    
    //    test2+=5;
    //    if(test2>ofGetHeight()){
    //        test2=0;
    //    }
    //
    //    for (int i=count; i<50; i++) {
    //        ofLine(lnx1,i* lny, test1,i* test2);
    //
    //
    //
    //
    //    }
    //
    //    test2+=5;
    //    if(test2>ofGetHeight()){
    //        test2=0;
    //    }
    
    
    
    
    //    for (int i=0; i<slices; i++) {
    //        gluPartialDisk(quadric, innerRadius, outerRadius, subdivisions,
    //                       concentricRings, i*sliceSize, sliceSize-gap);
    //    }
    
    //      float speed=10;
    //    ofLine(5, 5, 100, 600);
    //
    //    ofLine(0,0,50,600);
    //    x+=0.2;
    //
    //    ofLine(10,0,0,600);
    //    x+=0.2;
    //
    //    ofLine(15,0,30,600);
    //    x+=0.2;
    //
    //    ofLine(0,0,y*speed,600);
    //    y+=0.2;
    
    //    ofLine(0,x*speed,0,0);
    //    x+=1;
    
    
    //    float redValue=10.5;
    //    int redValueAsInt=12; //-2*63..2*63
    //    string name="DT";
    
    //
    //    ofColor someColor;
    //    someColor.r=255;
    //    someColor.g=0;
    //    someColor.b=60;
    //    ofSetColor(someColor);
    //      ofSetColor(theColor);
    //    ofRect(50,ofGetElapsedTimef()*speed,50,50);
    //    ofSetColor(255,255,255);
    //    ofRect(50,x*speed,50,50);
    //    x+=5;
    
    
    //   ofSetColor(someColor);
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key) {
        case 'a':
            theColor.b=255;
            break;
        case 'b':
            theColor.g=255;
            break;
            
        default:
            //if nothing matches
            break;
    }
    
    
    
    //theColor.g=255;
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    //theColor.g=0;
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
