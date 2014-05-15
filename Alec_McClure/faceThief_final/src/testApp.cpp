#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
#ifdef TARGET_OSX
	//ofSetDataPathRoot("../data/");
#endif
	ofSetVerticalSync(true);
	cloneReady = false;
	cam.initGrabber(640, 480);
	clone.setup(cam.getWidth(), cam.getHeight());
	ofFbo::Settings settings;
	settings.width = cam.getWidth();
	settings.height = cam.getHeight();
	maskFbo.allocate(settings);
	srcFbo.allocate(settings);
	camTracker.setup();
	srcTracker.setup();
	srcTracker.setIterations(25);
	srcTracker.setAttempts(4);

	faces.allowExt("jpg");
	faces.allowExt("png");
	faces.listDir("faces");
	currentFace = 0;
	if(faces.size()!=0){
		loadFace(faces.getPath(currentFace));
	}

	//start v4l2loopback virtual cam and begin picking up the feed
	system("data/WebcamJPG.sh&");
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		camTracker.update(toCv(cam));

		cloneReady = camTracker.getFound();
		if(cloneReady) {
			ofMesh camMesh = camTracker.getImageMesh();
			camMesh.clearTexCoords();
			camMesh.addTexCoords(srcPoints);

			maskFbo.begin();
			ofClear(0, 255);
			camMesh.draw();
			maskFbo.end();

			srcFbo.begin();
			ofClear(0, 255);
			src.bind();
			camMesh.draw();
			src.unbind();
			srcFbo.end();

			clone.setStrength(16);
			clone.update(srcFbo.getTextureReference(), cam.getTextureReference(), maskFbo.getTextureReference());
		}
	}


    recordImageFrames();


    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

void testApp::draw() {
	ofSetColor(255);

	if(src.getWidth() > 0 && cloneReady) {

		clone.draw(0, 0);
	} else {

        drawStatic();
        }



	if(!camTracker.getFound()) {
		//drawHighlightString("camera face not found", 10, 10);
	}
	if(src.getWidth() == 0) {
		//drawHighlightString("no image found", 10, 30);
	} else if(!srcTracker.getFound()) {
		//drawHighlightString("image face not found", 10, 30);
	}

	if(capBool){
		drawHighlightString("screencaptured", 10, 50);
		capBool = false;
		}
}

void testApp::loadFace(string face){
	src.loadImage(face);
	if(src.getWidth() > 0) {
		srcTracker.update(toCv(src));
		srcPoints = srcTracker.getImagePoints();
	}
}

void testApp::drawStatic(){




    pixelSize = 4;

		for (int i=0; i < ofGetWidth() / pixelSize; i++) {
            for (int j=0; j < ofGetHeight() / pixelSize; j++) {


                float xPos = i * pixelSize;
                float yPos = j * pixelSize;

                ofSetColor(ofNoise(ofGetElapsedTimef(), ofGetElapsedTimeMillis(), ofGetElapsedTimeMicros() )* 255);//ofNoise(sin(ofGetElapsedTimef())));// *ofRandom(255));
                ofRect(xPos, yPos, pixelSize, pixelSize);
            }
        }

}

void testApp::recordImageFrames() {

    int frameCap = 5;

	ofImage myImage;
	myImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());

   // if (flip){
   if (frameSelect <= frameCap){

    //myImage.saveImage("0" + ofToString(frameSelect) + ".png");
    myImage.saveImage("0" + ofToString(frameSelect) + ".jpg",OF_IMAGE_QUALITY_HIGH);}
    //system("gst-launch -v multifilesrc location=data/%02d.png loop=0 caps=\"image/png,framerate=30/1\" ! pngdec ! ffmpegcolorspace ! \"video/x-raw-yuv,format=(fourcc)YUY2\" ! videorate ! v4l2sink device=/dev/video1 &");
    //system("gst-launch -v multifilesrc location=data/%02d.jpg loop=1 caps=\"image/jpeg,framerate=1/1\" ! jpegdec ! ffmpegcolorspace ! \"video/x-raw-yuv,format=(fourcc)YUY2\" ! videorate ! v4l2sink device=/dev/video1 &");
    //system("gst-launch -v filesrc location=data/00.jpg ! jpegdec ! ffmpegcolorspace ! \"video/x-raw-yuv,format=(fourcc)YUY2\" ! videorate ! v4l2sink device=/dev/video1 &");


    if (frameSelect == frameCap) {
        frameSelect = 0;
    } else {
        frameSelect++;
    }

}

void testApp::dragEvent(ofDragInfo dragInfo) {
}

void testApp::keyPressed(int key){
    capBool = false;

	switch(key){
	case OF_KEY_UP:
		currentFace++;
		break;
	case OF_KEY_DOWN:
		currentFace--;
		break;
	case 'c':
		system("scrot data/faces/screenshot.png");
		capBool = true;
		break;
	}
	currentFace = ofClamp(currentFace,0,faces.size()-1);
	if(faces.size()!=0){
		loadFace(faces.getPath(currentFace));
	}


	cout << faces.getPath(currentFace) << endl;
}
