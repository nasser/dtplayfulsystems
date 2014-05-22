#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup() {
    
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    //ofEnableAlphaBlending();
    ofBackground(0);
    
    brush.loadImage("brush2.png");
    brush.resize(25, 500);
    
    maskFbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
#else
    if(ofGetGLProgrammableRenderer()){
    	string vertex = "#version 150\n\
    	\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelViewMatrix;\n\
    	uniform mat4 modelViewProjectionMatrix;\n\
    	\n\
    	\n\
    	in vec4  position;\n\
    	in vec2  texcoord;\n\
    	\n\
    	out vec2 texCoordVarying;\n\
    	\n\
    	void main()\n\
    	{\n\
        texCoordVarying = texcoord;\
        gl_Position = modelViewProjectionMatrix * position;\n\
    	}";
		string fragment = "#version 150\n\
		\n\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
		\
        out vec4 fragColor;\n\
		void main (void){\
		vec2 pos = texCoordVarying;\
		\
		vec3 src = texture(tex0, pos).rgb;\
		float mask = texture(maskTex, pos).r;\
		\
		fragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
		shader.bindDefaults();
		shader.linkProgram();
    }else{
		string shaderProgram = "#version 120\n \
		#extension GL_ARB_texture_rectangle : enable\n \
		\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
		\
		void main (void){\
		vec2 pos = gl_TexCoord[0].st;\
		\
		vec3 src = texture2DRect(tex0, pos).rgb;\
		float mask = texture2DRect(maskTex, pos).r;\
		\
		gl_FragColor = vec4( src , mask);\
		}";
		shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
		shader.linkProgram();
    }
#endif
    
    
    // Let's clear the FBO's
    // otherwise it will bring some junk with it from the memory
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    bBrushDown = true;
    
    //this is where the image sequence begins
    // read the directory for the images
    ofDirectory dir;
    
    int nFiles = dir.listDir("sunsetResized");
    if(nFiles) {
        
        for(int i=0; i<dir.numFiles(); i++) {
            
            // add the image to the vector
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().loadImage(filePath);
        }
    }
    // this toggle will tell the sequence
    // be be indepent of the app fps
    bFrameIndependent = true;
    
    // this will set the speed to play
    // the animation back we set the
    // default to 24fps
    sequenceFPS = 10;
    
    // set the app fps
    appFPS = 24;
    ofSetFrameRate(appFPS);
    
    tspsReceiver.connect( 12000 );
    ofxAddTSPSListeners(this);
}

//--------------------------------------------------------------
void testApp::update() {
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();

    
    ofPushMatrix();
    ofTranslate(0, 100);
    maskFbo.begin();
    if (bBrushDown){
        for (int i=0; i<people.size(); i++){
            ofPoint centroid = people[i]->centroid;
            centroid.x *= ofGetWidth();
            centroid.y *= ofGetHeight();
            
            brush.draw(centroid.x, centroid.y-100);
        }
    }
    maskFbo.end();
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    
    
    shader.begin();
    shader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1 );
    
    //DRAWING WITHIN THE SHADER WILL REVEAL WHAT'S UNDER THE FLASHLIGHT
    
    ofPushMatrix();
    // ofTranslate(50, 0);
    drawSkyline();
    ofPopMatrix();
    
    shader.end();
    fbo.end();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::draw() {
    ofSetColor(255,255, 255); //do not change
    vector<ofxTSPS::Person*> people = tspsReceiver.getPeople();

    
    ofPushMatrix();
    ofTranslate(0, 100);
    //  hand.draw(0, 0); //top image
    
    fbo.draw(0,0);
    maskFbo.begin();
    for (int i=0; i<people.size(); i++){
        ofPoint centroid = people[i]->centroid;
        centroid.x *= ofGetWidth();
        centroid.y *= ofGetHeight();
        brush.draw(centroid.x, centroid.y);
    }
    ofClear(0, 0, 0, 255);
    maskFbo.end();
    ofPopMatrix();
    
    
    
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if(key == OF_KEY_UP)      appFPS ++;
    if(key == OF_KEY_DOWN)    appFPS --;
    if(key == OF_KEY_LEFT)    sequenceFPS --;
    if(key == OF_KEY_RIGHT)   sequenceFPS ++;
    if(key == 't')            bFrameIndependent = !bFrameIndependent;
    
    // check for less than zero...
    sequenceFPS = MAX(sequenceFPS, 1);
    appFPS      = MAX(appFPS, 1);
    
    ofSetFrameRate(appFPS);
}

//--------------------------------------------------------------
void testApp::drawSkyline(){
    
    int frameIndex = 0;
    
    if(bFrameIndependent) {
        // calculate the frame index based on the app time
        // and the desired sequence fps. then mod to wrap
        frameIndex = (int)(ofGetElapsedTimef() * sequenceFPS) % images.size();
    }
    else {
        // set the frame index based on the app frame
        // count. then mod to wrap.
        frameIndex = ofGetFrameNum() % images.size();
    }
    
    // draw the image sequence at the new frame count
    ofSetColor(255);
    images[frameIndex].draw(0, 0);
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
    
    cout << "mouse x is: " << mouseX << " mouse y is: " << mouseY << endl;
    
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
void testApp::onPersonEntered(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "New person!");
}

//--------------------------------------------------------------
void testApp::onPersonUpdated(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person updated!");
}

//--------------------------------------------------------------
void testApp::onPersonWillLeave(ofxTSPS::EventArgs & tspsEvent){
    ofLog(OF_LOG_NOTICE, "Person left!");
}
