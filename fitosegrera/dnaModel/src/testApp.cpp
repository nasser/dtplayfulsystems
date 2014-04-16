#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//ofSetBackgroundAuto(false);
	ofBackground(0);
	/*ofColor colorOne;
	ofColor colorTwo;
	colorOne.set (255, 0, 0);
	colorTwo.set (0, 0, 255);
	ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);*/

	myLight.enable();
	myLight.setSpotlight();
	myLight.setSpotConcentration(100);
	myLight.setSpotlightCutOff(50);
	myLight.setPosition(0, 0, 600);

	origin.set(ofGetWidth()/2, ofGetHeight()/2, 800);
	cam.setTarget(origin);
	cam.setDistance(2000);

	ofSetVerticalSync(true);

    glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
    ofDisableArbTex(); //needed for textures to work with gluSphere

	//load textures
    dnaImage.loadImage("images/dna.jpg");
    bgImage.loadImage("images/bg.jpg");

	//prepare quadric for cylinder
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);

}

//--------------------------------------------------------------
void testApp::nucleotideDraw(int type2, float nucleoPosX, float nucleoPosY, float nucleoPosZ, float rotAngle, float rotX, float rotY, float rotZ){

	posX = ofGetWidth()/2;
	posY = ofGetHeight()/2;
	posZ = 0;
	radius = 10;
	height = 200;
	dnaImage.getTextureReference().bind();
	//gluSphere(quadric, 200, 100, 100);

	for (int i = 0; i < nucleoNum; ++i){
		//type.push_back(type2);
		if (type2 == 0){
		//GUANINE
			ofPushMatrix();
			ofSetColor(100,100,240);
			ofTranslate(posX, posY, posZ);
			ofRotate(rotAngle, rotX, rotY, rotZ);
			ofSetCylinderResolution(50, 100, 2);
			ofDrawCylinder(nucleoPosX, nucleoPosY, nucleoPosZ, radius, height);
			if (invert == true){
				ofDrawSphere(nucleoPosX, nucleoPosY + height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX - 15, nucleoPosY + height/2, nucleoPosZ + 50, 30);
			}else if(invert == false){
				ofDrawSphere(nucleoPosX, nucleoPosY - height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX + 15, nucleoPosY - height / 2, nucleoPosZ + 50, 30);
			}
			ofPopMatrix();
		}else if(type2 == 1){
		//CYTOSINE
			ofPushMatrix();
			ofSetColor(240,100,100);
			ofTranslate(posX, posY, posZ);
			ofRotate(rotAngle, rotX, rotY, rotZ);
			ofSetCylinderResolution(50, 100, 2);
			ofDrawCylinder(nucleoPosX, nucleoPosY, nucleoPosZ, radius, height);
			if (invert == true){
				ofDrawSphere(nucleoPosX, nucleoPosY + height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX - 15, nucleoPosY + height/2, nucleoPosZ + 50, 30);
			}else if(invert == false){
				ofDrawSphere(nucleoPosX, nucleoPosY - height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX + 15, nucleoPosY - height / 2, nucleoPosZ + 50, 30);
			}
			ofPopMatrix();
		}else if(type2 == 2){
		//ADENINE
			ofPushMatrix();
			ofSetColor(100,240,100);
			ofTranslate(posX, posY, posZ);
			ofRotate(rotAngle, rotX, rotY, rotZ);
			ofSetCylinderResolution(50, 100, 2);
			ofDrawCylinder(nucleoPosX, nucleoPosY, nucleoPosZ, radius, height);
			if (invert == true){
				ofDrawSphere(nucleoPosX, nucleoPosY + height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX - 15, nucleoPosY + height/2, nucleoPosZ + 50, 30);
			}else if(invert == false){
				ofDrawSphere(nucleoPosX, nucleoPosY - height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX + 15, nucleoPosY - height / 2, nucleoPosZ + 50, 30);
			}
			ofPopMatrix();
		}else if(type2 == 3){
		//THYMINE
			ofPushMatrix();
			ofSetColor(240,100,240);
			ofTranslate(posX, posY, posZ);
			ofRotate(rotAngle, rotX, rotY, rotZ);
			ofSetCylinderResolution(50, 100, 2);
			ofDrawCylinder(nucleoPosX, nucleoPosY, nucleoPosZ, radius, height);
			if (invert == true){
				ofDrawSphere(nucleoPosX, nucleoPosY + height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX - 15, nucleoPosY + height/2, nucleoPosZ + 50, 30);
			}else if(invert == false){
				ofDrawSphere(nucleoPosX, nucleoPosY - height/2, nucleoPosZ, 30);
				ofSetColor(255, 217, 0);
				ofDrawSphere(nucleoPosX + 15, nucleoPosY - height / 2, nucleoPosZ + 50, 30);
			}
			ofPopMatrix();
		}
	}
}
//--------------------------------------------------------------
void testApp::dnaDraw(int number){
	nucleoNum = number;
	if(drawState == true){
		for(int i = 0; i < number; i++){
			nucleoType2 = nucleoType[i];
			nucleotideDraw(nucleoType2, 0, -100, posChangeY, changeAngle, 0, 0, 1);
			if(nucleoType[i] == 0){
				invert = true;
				nucleotideDraw(1, 0, 100, posChangeY, changeAngle, 0, 0, 1);
				changeAngle += 10;
				posChangeY += 80;
			}else if(nucleoType[i] == 1){
				invert = true;
				nucleotideDraw(0, 0, 100, posChangeY, changeAngle, 0, 0, 1);
				changeAngle += 10;
				posChangeY += 80;
			}else if(nucleoType[i] == 2){
				invert = true;
				nucleotideDraw(3, 0, 100, posChangeY, changeAngle, 0, 0, 1);
				changeAngle += 10;
				posChangeY += 80;
			}else if(nucleoType[i] == 3){
				invert = true;
				nucleotideDraw(2, 0, 100, posChangeY, changeAngle, 0, 0, 1);
				changeAngle += 10;
				posChangeY += 80;
			}
			//cout<<nucleoType[i]<<endl;
			invert = false;	
		}
	}
	changeAngle = 90;
	posChangeY = 0;
	//drawState = false;
}

//--------------------------------------------------------------
void testApp::update(){
	/*if (drawState == true){
		for(int i = 0; i < nucleoNum; i++){
			nucleoType.push_back(int(ofRandom(4)));
		}
	}*/
	}

//--------------------------------------------------------------
	void testApp::draw(){

		ofSetColor(100,100,240);
		ofDrawBitmapString("Guanine", 20, 20);
		ofSetColor(240,100,100);
		ofDrawBitmapString("Cytosine", 20, 40);
		ofSetColor(100,240,100);
		ofDrawBitmapString("Adenine", 20, 60);
		ofSetColor(240,100,240);
		ofDrawBitmapString("Thymine", 20, 80);

		if(clicked == true){
			ofSetBackgroundAuto(true);
		}else{
			ofSetBackgroundAuto(false);
		}

		cam.begin();
		dnaDraw(30);
		cam.end();
		//dnaImage.draw(0,0);
	}

//--------------------------------------------------------------
	void testApp::keyPressed(int key){
		if(pressCounter == 1){
			for(int i = 0; i < nucleoNum; i++){
				nucleoType.push_back(int(ofRandom(4)));
				ofSetBackgroundAuto(false);
			}
			drawState = true;	
		}else if(pressCounter == 2){
			pressCounter = 0;
			drawState = false;
			ofSetBackgroundAuto(true);
		}	


	//ofSetBackgroundAuto(true);
		pressCounter ++;
	}

//--------------------------------------------------------------
	void testApp::keyReleased(int key){
	//ofSetBackgroundAuto(false);
	}

//--------------------------------------------------------------
	void testApp::mouseMoved(int x, int y ){

	}

//--------------------------------------------------------------
	void testApp::mouseDragged(int x, int y, int button){

	}

//--------------------------------------------------------------
	void testApp::mousePressed(int x, int y, int button){
		clicked = true;
	}

//--------------------------------------------------------------
	void testApp::mouseReleased(int x, int y, int button){
		clicked = false;
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
