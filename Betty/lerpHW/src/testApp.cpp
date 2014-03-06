#include "testApp.h"
#include "ofGraphics.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(125,65,65);
    ofEnableSmoothing();
    
    setBezierPoints();
    
    startAnim       = false;
    
    thisTime        = 0.0f;
    duration        = 6.5f;
    actualValue     = 0.0f;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // update animation of point
    animateValue(duration);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    ofNoFill();
    ofEnableAlphaBlending();
    
    // draw animated point
    pt = getBezier4Pt( startPoint,cP1, cP2,endPoint, actualValue);
    
    glPushMatrix();
    glTranslatef(0,0,pt.z);
    glColor4f(((pt.z+500)/1000.f),((pt.z+500)/1000.f),((pt.z+500)/1000.f),1);
    
    if(startAnim == true){
        ofCircle(pt.x,pt.y,6);
        ofCircle(pt.x,pt.y,9);
    }else{
        ofCircle(pt.x,pt.y,6);
    }
    glPopMatrix();
    
    
    // draw control points of bezier
    ofSetColor(0x000000);
    glPushMatrix();
    glTranslatef(0,0,startPoint.z);
    ofCircle(startPoint.x,startPoint.y,10);
    glPopMatrix();
    
    ofSetColor(0xFF0000);
    glPushMatrix();
    glTranslatef(0,0,cP1.z);
    ofCircle(cP1.x,cP1.y,3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,cP2.z);
    ofCircle(cP2.x,cP2.y,3);
    glPopMatrix();
    
    line3D(startPoint.x,startPoint.y,startPoint.z,cP1.x,cP1.y,cP1.z);
    line3D(endPoint.x,endPoint.y,endPoint.z,cP2.x,cP2.y,cP2.z);
    
    ofSetColor(0xffffff);
    glPushMatrix();
    glTranslatef(0,0,endPoint.z);
    ofCircle(endPoint.x,endPoint.y,6);
    glPopMatrix();
    
    
    // draw bezier curve
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
    glBegin(GL_TRIANGLE_STRIP);
    
    for( int i = 0; i < 101; i++)
    {
        glColor4f(((pt.z+500)/1000.f),((pt.z+500)/1000.f),((pt.z+500)/1000.f),0.6);
        pt = getBezier4Pt( startPoint,cP1, cP2,endPoint, i / 100.f );
        glVertex3f(pt.x-13.0,pt.y-13.0,pt.z-13.0);
        glVertex3f(pt.x+13.0,pt.y+13.0,pt.z+13.0);
        
    }
    glEnd();
    
    // draw controls
    
    ofSetColor(0xffffff);
    char buf[256];
    sprintf(buf,"X: %f,Y: %f,Z: %f",pt.x,pt.y,pt.z);
    ofDrawBitmapString(buf,20,600);
    
    sprintf(buf,"KEY 's' || 'S' - start time-based animation");
    ofDrawBitmapString(buf,20,650);
    
    sprintf(buf,"KEY 'd' || 'D' - redraw 3D bezier curve");
    ofDrawBitmapString(buf,20,670);
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    if(key  == 's' || key == 'S'){ // start animation
        actualValue = 0.0;
        thisTime = ofGetElapsedTimeMillis();
        startAnim = true;
    }
    
    if(key  == 'd' || key == 'D'){ // redraw bezier curve
        setBezierPoints();
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    
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
void testApp::mouseReleased(){
    
}
//--------------------------------------------------------------
void testApp::animateValue(float duration){
    
    if(startAnim){
        if(actualValue < 0.99f){
            actualValue = (((ofGetElapsedTimeMillis() - thisTime)/1000) )/(duration);
            //actualValue = (((ofGetElapsedTimeMillis() - thisTime)/1000) - 0.000001)/(duration - 0.000001) * 0.99f;
        }else{
            actualValue = 1.000000;
            startAnim = false;
        }
    }
    
}
//--------------------------------------------------------------
void testApp::setBezierPoints(){
    
    startPoint.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),ofRandom(-500,0));
    cP1.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),ofRandom(-200,200));
    cP2.set(ofRandom(20,ofGetWidth()-20),ofRandom(20,ofGetHeight()-20),ofRandom(-200,200));
    endPoint.set(ofRandom(400,ofGetWidth()-400),ofRandom(400,ofGetHeight()-400),ofRandom(0,500));
    
}
//--------------------------------------------------------------
void testApp::line3D(float x1,float y1,float z1,float x2,float y2,float z2){
    
	// draw:
	glBegin( GL_LINES );
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y2,z2);
	glEnd();
    
    
}
//--------------------------------------------------------------
