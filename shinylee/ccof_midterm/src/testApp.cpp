#include "testApp.h"

//major studio 2 project 
//--------------------------------------------------------------
void testApp::setup()
{
    ofBackground(0);
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    ofEnableSmoothing();
    
    //img.loadImage( "quad_warp_kittens.png" );
    myVideo.initGrabber(400, 300, true); //camera
    myVideo2.initGrabber(400, 300, true); //pixelate camera
    myPlayer.loadMovie("video2.mov"); //motion
    myPlayer.play();

    int x = 800;
    int y = 550;
    int w = myVideo.width;
    int h = myVideo.height;
    
    int x2 = 320;
    int y2 = 30;
    int w2 = myPlayer.width;
    int h2 = myPlayer.height;
    
    int x3 = 200;
    int y3 = 550;
    int w3 = myVideo2.width;
    int h3 = myVideo2.height;
    
    fbo.allocate( w, h );
    fbo2.allocate( w2, h2 );
    fbo3.allocate( w3, h3 );
    
    warper.setSourceRect( ofRectangle( 0, 0, w, h ) );              // this is the source rectangle which is the size of the image and located at ( 0, 0 )
    warper.setTopLeftCornerPosition( ofPoint( x, y ) );             // this is position of the quad warp corners, centering the image on the screen.
    warper.setTopRightCornerPosition( ofPoint( x + w, y ) );        // this is position of the quad warp corners, centering the image on the screen.
    warper.setBottomLeftCornerPosition( ofPoint( x, y + h ) );      // this is position of the quad warp corners, centering the image on the screen.
    warper.setBottomRightCornerPosition( ofPoint( x + w, y + h ) ); // this is position of the quad warp corners, centering the image on the screen.
    warper.setup();
    
    ////
    warper2.setSourceRect( ofRectangle( 0, 0, w2, h2) );     
    warper2.setTopLeftCornerPosition( ofPoint( x2, y2 ) );          
    warper2.setTopRightCornerPosition( ofPoint( x2 + w2, y2 ) );
    warper2.setBottomLeftCornerPosition( ofPoint( x2, y2 + h2 ) );     
    warper2.setBottomRightCornerPosition( ofPoint( x2 + w2, y2 + h2 ) );
    warper2.setup();
    
    ////
    warper3.setSourceRect( ofRectangle( 0, 0, w3, h3) );
    warper3.setTopLeftCornerPosition( ofPoint( x3, y3 ) );
    warper3.setTopRightCornerPosition( ofPoint( x3 + w3, y3 ) );
    warper3.setBottomLeftCornerPosition( ofPoint( x3, y3 + h3 ) );
    warper3.setBottomRightCornerPosition( ofPoint( x3 + w3, y3 + h3 ) );
    warper3.setup();
    
 }

//--------------------------------------------------------------
void testApp::update()

{
   myVideo.update();//img.update();
   myVideo2.update();
   myPlayer.update(); 
    
    if( ofGetFrameNum() % 5 != 0 ) // only update every 5 frames.
        return;    
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofSetColor( ofColor :: white );
    
    //======================== draw image into fbo.
    
    fbo.begin();
    {
        myVideo.draw( 0, 0 );
    }
    fbo.end();
    
    fbo2.begin();
    {
        myPlayer.draw( 0, 0 );
    }
    fbo2.end();
    
    fbo3.begin();
    {
        myVideo2.draw( 0, 0 );
        
        ofSetColor(0); // 0 or 255?
        ofRect(0,0,1000,1000);
        
        unsigned char * pixels = myVideo2.getPixels();
        
        int skip = 12;
       
        for (int i = 0; i < myVideo2.width; i = i + skip){
            for (int j = 0; j < myVideo2.height; j = j + skip){
                
                int r = pixels[j * myVideo2.width * 3 + i * 3];
                int g = pixels[j * myVideo2.width * 3 + i * 3 + 1];
                int b = pixels[j * myVideo2.width * 3 + i * 3 + 2];
                
                int brightness = (r + g + b) / 3.0f * 255.0f;
                float pct = (r + g + b) / 3.0f / 255.0f;
                
                ofSetColor(252,74,180);
                ofPushMatrix();
                ofTranslate(i, j);
                ofRotateZ(pct * 180);
                ofCircle(0, 0, pct * skip * 0.5);
                ofPopMatrix();
            }
        }
    }
    fbo3.end();
    
    ofSetColor(255,255,255);
    
    //======================== get our quad warp matrix.
    
    ofMatrix4x4 mat = warper.getMatrix();
    ofMatrix4x4 mat2 = warper2.getMatrix();
    ofMatrix4x4 mat3 = warper3.getMatrix();
    
    //======================== use the matrix to transform our fbo.
    
    glPushMatrix();
    glMultMatrixf( mat.getPtr() );
    {
        fbo.draw( 0, 0 );
    }
    glPopMatrix();
    
    ///
    glPushMatrix();
    glMultMatrixf( mat2.getPtr() );
    {
        fbo2.draw(0, 0);
    }
    glPopMatrix();
    
    ///
    glPushMatrix();
    glMultMatrixf( mat3.getPtr() );
    {
        fbo3.draw(0, 0);
    }
    glPopMatrix();
        
    //======================== draw quad warp ui.
    
    ofSetColor( ofColor :: magenta );
    warper.draw();
    warper2.draw();
    warper3.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    if( key == 's' )
        warper.toggleShow();
        warper2.toggleShow();
        warper3.toggleShow();
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