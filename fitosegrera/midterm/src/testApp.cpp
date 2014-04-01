#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    //VARIABLES FOR TEXT INPUT BOX
    string  text = "";
    int position = 0;
    int cursorx = 0;
    int cursory = 0;

    //GLOBAL LIGHT PROPERTIES
    ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSmoothLighting(true);

    //LOAD IMAGES
    image.loadImage("images/0.jpg");
    //image.loadImage("images/1.jpg");
    //image.loadImage("images/2.jpg");
    //image.loadImage("images/3.jpg");
    //image.loadImage("images/4.jpg");
    image.resize(200, 200);

    //LOAD SOUND FILES
    snapSound.loadSound("sounds/snapshot.mp3"); //LOAD snapshot sound effect
    //ambient.loadSound("sounds/ambient.mp3"); //LOAD atmosphere sound effect
    //ambient.play(); //PLAY atmosphere
    //ambient.setLoop(true); //set Atmosphere to infinite loop

}
//--------------------------------------------------------------
//FUNCTION TO DRAW THE BACKGROUND OF THE GUI
void gui::drawBackground(int posX, int posY, int scaleX, int scaleY, int transBackground, string title, string description){
    ofSetRectMode(OF_RECTMODE_CORNER);
    myFont2.loadFont("modes.TTF", 12);
    myFont2.drawString(title, 20, 30);
    myFont3.loadFont("modes.TTF", 8);
    myFont3.drawString(description, 20, 43);
    myFont3.drawString("------------------------------", 20, 15);
    myFont3.drawString("------------------------------", 20, 55);
    myFont3.drawString("INSTRUCTIONS:",20,80);
    myFont3.drawString("For CAMERA use mouse right click to",20,90);
    myFont3.drawString("rotate & use mouse left click to zoom",20,100);
    myFont3.drawString("Toggle buttons & slides to change",20,110);
    myFont3.drawString("the parameters of the image.",20,120);
    myFont3.drawString("Hit GENERATE to render",20,130);
    myFont3.drawString("Hit CLEAR to reset",20,140);
    myFont3.drawString("For MENU ON/OFF press space_bar...",20,150);
    myFont3.drawString("SAVE image by pressing 's' ",20,160);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(0, 0, 0, transBackground);
    ofRect(posX, posY, scaleX, scaleY);
}
//--------------------------------------------------------------
//FUNCTION TO DRAW BUTTONS FROM THE GUI
void gui::drawButton(int posX, int posY, int scaleX, int scaleY, int transparency, string name){
    myFont.loadFont("modes.TTF", 8);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(100, 100, 100, transparency);
    ofRect(posX, posY, scaleX, scaleY);
    ofSetColor(color);
    ofRect(posX, posY, scaleX - 4, scaleY - 4);
    ofSetColor(150);
    //myFont.drawString(name, posX - myFont.stringWidth(name)/2, posY + scaleY/2 + 20);
    myFont.drawString(name, posX - scaleX/2 + 10, posY + 4);
    //cout << myFont.stringWidth(name) << endl;
    checkPosX = posX;
    checkPosY = posY;
    checkScaleX = scaleX;
    checkScaleY = scaleY;
}
//--------------------------------------------------------------
//FUNCTION TO DRAW SLIDERS FROM THE GUI
void gui::drawSlide(int posX, int posY, int scaleX, int scaleY, int tranSlide, string slideName){
    myFont.loadFont("modes.TTF", 8);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(100, 100, 100, tranSlide);
    ofRect(posX, posY, scaleX, scaleY);
    //cout << myFont.stringWidth(name) << endl;
    checkSlidePosX = posX;
    checkSlidePosY = posY;
    checkSlideScaleX = scaleX;
    checkSlideScaleY = scaleY;

    ofSetColor(red, green, blue, 80);
    ofRect(posX + 4, posY + 4, checkIntSlideScaleX + 4, scaleY - 8);

    ofSetColor(150);
    myFont.drawString(slideName + ofToString(checkIntSlideScaleX), posX + scaleX + myFont.getSize()/2, posY + scaleY/2 + myFont.getSize()/2);
}
//--------------------------------------------------------------
//FUNCTION TO DRAW SAVE BOX FROM THE GUI
void gui::drawSaveBox(int posX, int posY, int scaleX, int scaleY, int transSaveBox, string fileName){
    ofSetRectMode(OF_RECTMODE_CENTER);
    saveBoxFont.loadFont("modes.TTF", 8);
    ofSetColor(100, 100, 100, transSaveBox);
    ofRect(posX, posY, scaleX, scaleY); //Draws the main rectangle box
    ofSetColor(10, 10, 10, transSaveBox + (100 - transSaveBox)/2);
    ofRect(posX, posY, scaleX - 10, scaleY - 10); //Draws the inner darker rectangle box
    ofSetColor(150);
    saveBoxFont.drawString(fileName, posX - scaleX/2.5, posY - scaleY/4); //Draws the text "save image as..."
    ofSetColor(0, 0, 0, 90);
    ofRect(posX, posY, scaleX/1.25, scaleY/5); //Draws the text input box
    posButCancelX = posX - scaleX/3.6;
    posButCancelY = posY + scaleY/3.5;
    posButSaveX = posX + scaleX/3.6;
    posButSaveY = posY + scaleY/3.5; 
    scaleButtonsX = scaleX/4;
    scaleButtonsY = scaleY/5;
    transButtons = transSaveBox + (100 - transSaveBox)/4;
    drawButton(posButCancelX, posButCancelY, scaleButtonsX, scaleButtonsY, transButtons, "cancel");
    drawButton(posButSaveX, posButSaveY, scaleButtonsX, scaleButtonsY, transButtons, " save");
    saveTextPosX = posX - scaleX/2.6;
    saveTextPosY = posY + 4;

}
//--------------------------------------------------------------
//The folowing function allows this GUI to have a text input box for the "save image box" 
//the original code was created by elliot woods / Simple-text-buffer-for-openFrameworks please visit: 
//https://github.com/elliotwoods/Simple-text-buffer-for-openFrameworks/tree/VerySimple
void testApp::typeKey(int key) {
//add charachter
    if (key >=32 && key <=126) {
        text.insert(text.begin()+position, key);
        position++;
        cursorx++;
    }

    // if (key==OF_KEY_RETURN) {
    //     text.insert(text.begin()+position, '\n');
    //     position++;
    // }

    if (key==OF_KEY_BACKSPACE) {
        if (position>0) {
            text.erase(text.begin()+position-1);
            position--;
            cursorx--;
        }
    }

    if (key==OF_KEY_DEL) {
        if (text.size() > position) {
            text.erase(text.begin()+position);
        }
    }


}
//--------------------------------------------------------------
//Function for stablishing the spot-light's orientation. Based on the example at: http://forum.openframeworks.cc/t/oflight-gl-lighting-basic-beginner-example/12027
void testApp::setLightOri(ofLight &light, ofVec3f rot){
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
}
//--------------------------------------------------------------
void testApp::update(){
    if(generateStop == true){
        //IF lINES BUTTON IS PRESSED... SWITCH BETWEEN LINES AND DOTS
        if(checkLines == true){   
            mesh.setMode(OF_PRIMITIVE_LINES);    
        }else {
            mesh.setMode(OF_PRIMITIVE_POINTS); 
        }

        w = image.getWidth();
        h = image.getHeight();

        float intensityThresh = slide1.checkIntSlideScaleX * 2; //Set the intensity threshold of the image's light based on the slider configuration

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                ofColor color = image.getColor(i,j);
                float intensity = color.getLightness();
                if(intensity >= intensityThresh){
                    float saturation = color.getSaturation();
                    float z = ofMap(saturation, 0, 255, -200, 200);
                    ofVec3f pos(4*i, 4*j, z);
                    mesh.addVertex(pos);
                    mesh.addColor(color);
                }
            }
        }

        float connectionDistance = slide2.checkIntSlideScaleX;
        int numVerts = mesh.getNumVertices();
        for (int a=0; a<numVerts; ++a) {
            ofVec3f verta = mesh.getVertex(a);
            for (int b=a+1; b<numVerts; ++b) {
                ofVec3f vertb = mesh.getVertex(b);
                float distance = verta.distance(vertb);
                if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
                }
            }
        }
    }
    generateStop = false;
}
//-------------------------------------------------------------
//The folowing function allows this GUI to have a text input box for the "save image box" 
//the original code was created by elliot woods / Simple-text-buffer-for-openFrameworks please visit: 
//https://github.com/elliotwoods/Simple-text-buffer-for-openFrameworks/tree/VerySimple
void testApp::drawText() {
    ofDrawBitmapString(text, saveBox.saveTextPosX, saveBox.saveTextPosY);

    ofPushStyle();
    float timeFrac = 200.0 * sin(5.0 * ofGetElapsedTimef());
    ofSetColor(255,255,255, timeFrac);
    ofSetLineWidth(2.0);
    ofLine(saveBox.saveTextPosX + 3 + position * 8, saveBox.saveTextPosY - 8, saveBox.saveTextPosX + 3 + position * 8, saveBox.saveTextPosY);
    ofPopStyle();
}
//-------------------------------------------------------------
void testApp::draw(){
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofColor centerColor = ofColor(slideBackColorR.red, slideBackColorG.green, slideBackColorB.blue);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    initMessageFont.loadFont("modes.TTF", 8);
    ofSetColor(100, 100, 100, 50);

    //IF THE GENERATE BUTTON IS PRESSED...
    if(generate == true){
        easyCam.begin();
            ofPushMatrix();
            //LIGHT SETTINGS - IF LIGHT BUTTON IS PRESSED...
            if(checkLight == true){
                light.setDiffuseColor(ofFloatColor(5.0, 5.0, 5.0));
                light.setSpecularColor(ofColor(255, 255, 255));
                light.setSpotlight();
                light.setSpotConcentration(5);
                light.setSpotlightCutOff(100);
                light_rot = ofVec3f(slideLightRotX.checkIntSlideScaleX, slideLightRotY.checkIntSlideScaleX, slideLightRotZ.checkIntSlideScaleX);
                setLightOri(light, light_rot);
                light.setPosition(0, 0, 1000);
                light.enable();
            }else{
                light.disable();
                ofDisableLighting();
            }
                ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
                mesh.draw();
            ofPopMatrix();
        easyCam.end();
    }
    //If the CLEAR button is pressed...
    if(clear == true){
        mesh.clear(); //Clear the whole mesh
        clear = false; //Reset the clear boolean to FALSE
        slideBackColorR.checkIntSlideScaleX = 0; //Set the Background RED value to 0
        slideBackColorG.checkIntSlideScaleX = 0; //Set the Background GREEN value to 0
        slideBackColorB.checkIntSlideScaleX = 0; //Set the Background BLUE value to 0
        slideBackColorR.red = 0;
        slideBackColorG.green = 0; 
        slideBackColorB.blue = 0;
        generate = false;
    }

    ofSetColor(200);

    ofPushMatrix(); //Creates a separate layer for the MENU DRAW
    //IF MENU BOLLEAN IS TRUE...
    if(menu == true){
        easyCam.disableMouseInput(); //DISABLE camera mouse interaction when menu appears 
        light.disable(); //Disables light properties for the menu layer
        ofDisableLighting(); //Disables light properties for the menu layer
        background.drawBackground(0, 0, 260, 550, 50, "DT-PLAYFUL-SYSTEMS", "Interface by fito_segrera"); //Draw Back rectangle
        slide1.drawSlide(20, 170, 100, 20, 50, "Intensity Thresh: "); //Draw Slider1
        slide2.drawSlide(20, 200, 100, 20, 50, "Connection Dist: "); //Draw Slider2

        slideBackColorR.drawSlide(20, 230, 100, 20, 50, "Red Value: "); //Draw Slider Background RED
        slideBackColorG.drawSlide(20, 260, 100, 20, 50, "Green Value: "); //Draw Slider Background GREEN
        slideBackColorB.drawSlide(20, 290, 100, 20, 50, "Blue Value: "); //Draw Slider Background BLUE

        slideLightRotX.drawSlide(20, 320, 100, 20, 50, "Light Rot_X: "); //Light rotation X Slider
        slideLightRotY.drawSlide(20, 350, 100, 20, 50, "Light Rot_Y: "); //Light rotation Y Slider
        slideLightRotZ.drawSlide(20, 380, 100, 20, 50, "Light Rot_Z: "); //Light rotation Z Slider

        buttonLines.drawButton(20 + buttonLines.checkScaleX/2, 430, 20, 20, 50, "   Activate lines"); //Button for activating or deactivating lines
        buttonLight.drawButton(20 + buttonLight.checkScaleX/2, 470, 20, 20, 50, "   Light on/off"); //Button for turning light on/off

        button1.drawButton(20 + button1.checkScaleX/2, 510, 70, 30, 50, "GENERATE"); //DRAW GENERATE BUTTON - The argumets that this takes are: posX, posY, scaleX, scaleY, transparency
        buttonClear.drawButton(110 + buttonClear.checkScaleX/2, 510, 70, 30, 50, " CLEAR"); //DRAW CLEAR BUTTON

    //WRITE INITIAL MESSAGE ONLY IF SCREEN IS CLEAR AND MENU IS NOT THERE...
    }else{
        easyCam.enableMouseInput(); //ENABLE camera's mouse interaction when menu is off
        if(initMessage == false && generate == false){
            //IF MENU BOOLEAN IS FALSE...
            string initMessage = "for MENU press space bar..."; //Declare a string variable with the initial message
            ofRectangle textBox = initMessageFont.getStringBoundingBox(initMessage, 0,0); //get the size of the bounding box of the string as a rectangle
            initMessageFont.drawString(initMessage, ofGetWidth()/2 - textBox.width/2, ofGetHeight()/2); //draw the text in the center of the screen
        } 
    } 
    ofPopMatrix();

    if(captureImageState == true){
        snapSound.play();
        screenCapture.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        screenCapture.saveImage("snapshots/"+ text + ".png");
        captureImageState = false;
        text = "";
        cout<< "saved!" <<endl;
    }

    if(saveBoxState == true){
        saveBox.drawSaveBox(ofGetWidth()/2, ofGetHeight()/2, 250, 100, 95, "Save image as...");
        ofPushMatrix();
        drawText();
        ofPopMatrix();
        if(saveButState == true){
            saveBoxState = false;
            saveButState = false;
            captureImageState = true;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(saveBoxState == true){
        if(position <= 23){
            typeKey(key);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == ' '){
        menu = !menu;
    }
    if(key == 's' || key == 'S'){
        if(generate == true)
        {
            saveBoxState = true;
            cout<<"save image as..."<<endl;
        }
    }else if(key == 's' || key == 'S'){
        if(generate == false)
        {
            saveBoxState = false;
        }
    }
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (menu == true){
        
        if (mouseX >= slide1.checkSlidePosX + 10 && mouseX <= slide1.checkSlidePosX + slide1.checkSlideScaleX && 
            mouseY >= slide1.checkSlidePosY && mouseY <= slide1.checkSlidePosY + slide1.checkSlideScaleY){
            slide1.color = 100;
            slide1.checkIntSlideScaleX = slide1.checkSlidePosX - slide1.checkSlideScaleX/2 + mouseX;
        }
        if (mouseX >= slide2.checkSlidePosX + 10 && mouseX <= slide2.checkSlidePosX + slide2.checkSlideScaleX && 
            mouseY >= slide2.checkSlidePosY && mouseY <= slide2.checkSlidePosY + slide2.checkSlideScaleY){
            slide2.color = 100;
            slide2.checkIntSlideScaleX = slide1.checkSlidePosX - slide2.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the RED slider
        if (mouseX >= slideBackColorR.checkSlidePosX + 10 && mouseX <= slideBackColorR.checkSlidePosX + slideBackColorR.checkSlideScaleX && 
            mouseY >= slideBackColorR.checkSlidePosY && mouseY <= slideBackColorR.checkSlidePosY + slideBackColorR.checkSlideScaleY){
            slideBackColorR.red = 255;
            slideBackColorR.green = 50;
            slideBackColorR.blue = 50;
            slideBackColorR.checkIntSlideScaleX = slideBackColorR.checkSlidePosX - slideBackColorR.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the GREEN slider
        if (mouseX >= slideBackColorG.checkSlidePosX + 10 && mouseX <= slideBackColorG.checkSlidePosX + slideBackColorG.checkSlideScaleX && 
            mouseY >= slideBackColorG.checkSlidePosY && mouseY <= slideBackColorG.checkSlidePosY + slideBackColorG.checkSlideScaleY){
            slideBackColorG.red = 50;
            slideBackColorG.green = 255;
            slideBackColorG.blue = 50;
            slideBackColorG.checkIntSlideScaleX = slideBackColorG.checkSlidePosX - slideBackColorG.checkSlideScaleX/2 + mouseX;
            //cout << slide1.checkIntSlideScaleX << endl;
        }
        //Check if clicked inside the BLUE slider
        if (mouseX >= slideBackColorB.checkSlidePosX + 10 && mouseX <= slideBackColorB.checkSlidePosX + slideBackColorB.checkSlideScaleX && 
            mouseY >= slideBackColorB.checkSlidePosY && mouseY <= slideBackColorB.checkSlidePosY + slideBackColorB.checkSlideScaleY){
            slideBackColorB.red = 50;
            slideBackColorB.green = 50;
            slideBackColorB.blue = 255;
            slideBackColorB.checkIntSlideScaleX = slideBackColorB.checkSlidePosX - slideBackColorB.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_X slider
        if (mouseX >= slideLightRotX.checkSlidePosX + 10 && mouseX <= slideLightRotX.checkSlidePosX + slideLightRotX.checkSlideScaleX && 
            mouseY >= slideLightRotX.checkSlidePosY && mouseY <= slideLightRotX.checkSlidePosY + slideLightRotX.checkSlideScaleY){
            slideLightRotX.red = 180;
            slideLightRotX.green = 180;
            slideLightRotX.blue = 180;
            slideLightRotX.checkIntSlideScaleX = slideLightRotX.checkSlidePosX - slideLightRotX.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_Y slider
        if (mouseX >= slideLightRotY.checkSlidePosX + 10 && mouseX <= slideLightRotY.checkSlidePosX + slideLightRotY.checkSlideScaleX && 
            mouseY >= slideLightRotY.checkSlidePosY && mouseY <= slideLightRotY.checkSlidePosY + slideLightRotY.checkSlideScaleY){
            slideLightRotY.red = 180;
            slideLightRotY.green = 180;
            slideLightRotY.blue = 180;
            slideLightRotY.checkIntSlideScaleX = slideLightRotY.checkSlidePosX - slideLightRotY.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_Z slider
        if (mouseX >= slideLightRotZ.checkSlidePosX + 10 && mouseX <= slideLightRotZ.checkSlidePosX + slideLightRotZ.checkSlideScaleX && 
            mouseY >= slideLightRotZ.checkSlidePosY && mouseY <= slideLightRotZ.checkSlidePosY + slideLightRotZ.checkSlideScaleY){
            slideLightRotZ.red = 180;
            slideLightRotZ.green = 180;
            slideLightRotZ.blue = 180;
            slideLightRotZ.checkIntSlideScaleX = slideLightRotZ.checkSlidePosX - slideLightRotZ.checkSlideScaleX/2 + mouseX;
        }
    }
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (menu == true){

        //Check if clicked inside the slider1
        if (mouseX >= slide1.checkSlidePosX + 10 && mouseX <= slide1.checkSlidePosX + slide1.checkSlideScaleX && 
            mouseY >= slide1.checkSlidePosY && mouseY <= slide1.checkSlidePosY + slide1.checkSlideScaleY){
            slide1.red = 180;
            slide1.green = 180;
            slide1.blue = 180;
            slide1.checkIntSlideScaleX = slide1.checkSlidePosX - slide1.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the slider2
        if (mouseX >= slide2.checkSlidePosX + 10 && mouseX <= slide2.checkSlidePosX + slide2.checkSlideScaleX && 
            mouseY >= slide2.checkSlidePosY && mouseY <= slide2.checkSlidePosY + slide2.checkSlideScaleY){
            slide2.red = 180;
            slide2.green = 180;
            slide2.blue = 180;
            slide2.checkIntSlideScaleX = slide2.checkSlidePosX - slide2.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the RED slider
        if (mouseX >= slideBackColorR.checkSlidePosX + 10 && mouseX <= slideBackColorR.checkSlidePosX + slideBackColorR.checkSlideScaleX && 
            mouseY >= slideBackColorR.checkSlidePosY && mouseY <= slideBackColorR.checkSlidePosY + slideBackColorR.checkSlideScaleY){
            slideBackColorR.red = 255;
            slideBackColorR.green = 50;
            slideBackColorR.blue = 50;
            slideBackColorR.checkIntSlideScaleX = slideBackColorR.checkSlidePosX - slideBackColorR.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the GREEN slider
        if (mouseX >= slideBackColorG.checkSlidePosX + 10 && mouseX <= slideBackColorG.checkSlidePosX + slideBackColorG.checkSlideScaleX && 
            mouseY >= slideBackColorG.checkSlidePosY && mouseY <= slideBackColorG.checkSlidePosY + slideBackColorG.checkSlideScaleY){
            slideBackColorG.red = 50;
            slideBackColorG.green = 255;
            slideBackColorG.blue = 50;
            slideBackColorG.checkIntSlideScaleX = slideBackColorG.checkSlidePosX - slideBackColorG.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the BLUE slider
        if (mouseX >= slideBackColorB.checkSlidePosX + 10 && mouseX <= slideBackColorB.checkSlidePosX + slideBackColorB.checkSlideScaleX && 
            mouseY >= slideBackColorB.checkSlidePosY && mouseY <= slideBackColorB.checkSlidePosY + slideBackColorB.checkSlideScaleY){
            slideBackColorB.red = 50;
            slideBackColorB.green = 50;
            slideBackColorB.blue = 255;
            slideBackColorB.checkIntSlideScaleX = slideBackColorB.checkSlidePosX - slideBackColorB.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_X slider
        if (mouseX >= slideLightRotX.checkSlidePosX + 10 && mouseX <= slideLightRotX.checkSlidePosX + slideLightRotX.checkSlideScaleX && 
            mouseY >= slideLightRotX.checkSlidePosY && mouseY <= slideLightRotX.checkSlidePosY + slideLightRotX.checkSlideScaleY){
            slideLightRotX.red = 180;
            slideLightRotX.green = 180;
            slideLightRotX.blue = 180;
            slideLightRotX.checkIntSlideScaleX = slideLightRotX.checkSlidePosX - slideLightRotX.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_Y slider
        if (mouseX >= slideLightRotY.checkSlidePosX + 10 && mouseX <= slideLightRotY.checkSlidePosX + slideLightRotY.checkSlideScaleX && 
            mouseY >= slideLightRotY.checkSlidePosY && mouseY <= slideLightRotY.checkSlidePosY + slideLightRotY.checkSlideScaleY){
            slideLightRotY.red = 180;
            slideLightRotY.green = 180;
            slideLightRotY.blue = 180;
            slideLightRotY.checkIntSlideScaleX = slideLightRotY.checkSlidePosX - slideLightRotY.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the LIGHT ROT_Z slider
        if (mouseX >= slideLightRotZ.checkSlidePosX + 10 && mouseX <= slideLightRotZ.checkSlidePosX + slideLightRotZ.checkSlideScaleX && 
            mouseY >= slideLightRotZ.checkSlidePosY && mouseY <= slideLightRotZ.checkSlidePosY + slideLightRotZ.checkSlideScaleY){
            slideLightRotZ.red = 180;
            slideLightRotZ.green = 180;
            slideLightRotZ.blue = 180;
            slideLightRotZ.checkIntSlideScaleX = slideLightRotZ.checkSlidePosX - slideLightRotZ.checkSlideScaleX/2 + mouseX;
        }
        //Check if clicked inside the lines button
        if (mouseX >= buttonLines.checkPosX - buttonLines.checkScaleX/2 && mouseX <= buttonLines.checkPosX + buttonLines.checkScaleX/2 
            && mouseY >= buttonLines.checkPosY - buttonLines.checkScaleY/2 && mouseY <= buttonLines.checkPosY + buttonLines.checkScaleY/2){
            checkLines = !checkLines;
            if(checkLines == true){
                buttonLines.color = 50;
            }else{
                buttonLines.color = 10;
            }
        }
        //Check if clicked inside the LIGHT button
        if (mouseX >= buttonLight.checkPosX - buttonLight.checkScaleX/2 && mouseX <= buttonLight.checkPosX + buttonLight.checkScaleX/2 
            && mouseY >= buttonLight.checkPosY - buttonLight.checkScaleY/2 && mouseY <= buttonLight.checkPosY + buttonLight.checkScaleY/2){
            checkLight = !checkLight;
            if(checkLight == true){
                buttonLight.color = 50;
            }else{
                buttonLight.color = 10;
            }
        }
        //Check if clicked inside the GENERATE button
        if (mouseX >= button1.checkPosX - button1.checkScaleX/2 && mouseX <= button1.checkPosX + button1.checkScaleX/2 
            && mouseY >= button1.checkPosY - button1.checkScaleY/2 && mouseY <= button1.checkPosY + button1.checkScaleY/2){
            //button1.color = 100;
            generate = true;
            generateStop = true;
        }
        //Check if clicked inside the CLEAR button
        if (mouseX >= buttonClear.checkPosX - buttonClear.checkScaleX/2 && mouseX <= buttonClear.checkPosX + buttonClear.checkScaleX/2 
            && mouseY >= buttonClear.checkPosY - buttonClear.checkScaleY/2 && mouseY <= buttonClear.checkPosY + buttonClear.checkScaleY/2){
            //button1.color = 100;
            clear = true;
        }
    }
    //Check if SAVE button is pressed from the save image box
    if(saveBoxState == true){
        if (mouseX >= saveBox.posButSaveX - saveBox.scaleButtonsX/2 && mouseX <= saveBox.posButSaveX + saveBox.scaleButtonsX/2 && 
            mouseY >= saveBox.posButSaveY - saveBox.scaleButtonsY/2 && mouseY <= saveBox.posButSaveY + saveBox.scaleButtonsY/2){
            saveButState = true;
        }
    }
    //Check if CANCEL button is pressed from the save image box
    if(saveBoxState == true){
        if (mouseX >= saveBox.posButCancelX - saveBox.scaleButtonsX/2 && mouseX <= saveBox.posButCancelX + saveBox.scaleButtonsX/2 && 
            mouseY >= saveBox.posButCancelY - saveBox.scaleButtonsY/2 && mouseY <= saveBox.posButCancelY + saveBox.scaleButtonsY/2){
            cout << "save image cancelled..." << endl;
            saveBoxState = false;
            text = "";
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){    
     button1.color = 10;
     
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
