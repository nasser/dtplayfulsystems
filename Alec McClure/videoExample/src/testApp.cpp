#include "testApp.h"

//#include <stdio.h> //SWITCH BACK ON FOR PI
//#include <wiringPi.h> //SWITCH BACK ON FOR PI
#include "ledHashTable.h" //hash table

#define CLK	11
#define SCLK	10
#define A	4
#define B	1
#define	OE	5
#define PIXEL	6

//--------------------------------------------------------------
void testApp::setup(){
/*
    pinMode (CLK, OUTPUT); //INITIALIZE WIRING PI PINS
    pinMode (SCLK, OUTPUT); //INITIALIZE WIRING PI PINS
    pinMode (A, OUTPUT); //INITIALIZE WIRING PI PINS
    pinMode (B, OUTPUT); //INITIALIZE WIRING PI PINS
    pinMode (OE, OUTPUT); //INITIALIZE WIRING PI PINS
    pinMode (CLK, OUTPUT); //INITIALIZE WIRING PI PINS
*/
	camWidth 		= 640;	// try to grab at this size.
	camHeight 		= 480;

	myfont.loadFont("arial.ttf", 12);

    //we can now get back a list of devices.
	vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(int i = 0; i < devices.size(); i++){
		cout << devices[i].id << ": " << devices[i].deviceName;
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
	}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(30);
	vidGrabber.initGrabber(camWidth,camHeight);

	//videoInverted 	= new unsigned char[camWidth*camHeight*3];
	//videoTexture.allocate(camWidth,camHeight, GL_LUMINANCE);
	ofSetVerticalSync(true);


	verticalFlip = new unsigned char[camWidth*camHeight*3];
    //horizontalFlip = new unsigned char[camWidth*camHeight*3];
}


//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.update();
}
        //////////////////// BEGIN IMPORTED LOGIC /////////////////

void digitalWrite(int led, int status){ //ONLY HERE TO CHECK FOR ERRORS

}

void select_row(int row){

	digitalWrite(SCLK, 1);// output_high(SCLK);				// Idle state for row clock line
	digitalWrite(SCLK, 1);// output_high(SCLK);				// Idle state for row clock line
	if (row==0)
	{
		digitalWrite(A, 0);//output_low(A);
		digitalWrite(B, 0);//output_low(B);
	}
	if (row==1)
	{
		digitalWrite(A, 1);//output_high(A);
		digitalWrite(B, 0);//output_low(B);
	}
	if (row==2)
	{
		digitalWrite(A, 0);//output_low(A);
		digitalWrite(B, 1);//output_high(B);
	}
	if (row==3)
	{
		digitalWrite(A, 1);//output_high(A);
		digitalWrite(B, 1);//output_high(B);
	}
	//output_low(SCLK);				// Indicate board should take new address for active ROW
	//output_low(SCLK);				// Indicate board should take new address for active ROW
	//output_low(SCLK);				// Indicate board should take new address for active ROW
    digitalWrite(SCLK, 0);
    digitalWrite(SCLK, 0);
    digitalWrite(SCLK, 0);
	digitalWrite(SCLK, 1);
	digitalWrite(SCLK, 1);
	digitalWrite(SCLK, 1);
	//output_high(SCLK);				// Idle state
	//output_high(SCLK);				// Idle state
	//output_high(SCLK);				// Idle state

}

void update_leds()
{
	// Now we have 1024 pixels clocked in update the display
	digitalWrite(OE, 0);
    digitalWrite(OE, 0);
    digitalWrite(OE, 0);
    digitalWrite(OE, 0);
    digitalWrite(OE, 1);
    digitalWrite(OE, 1);
    digitalWrite(OE, 1);
    digitalWrite(OE, 1);

}

void clock_pixels(unsigned char *ptr,int numpixels)
{
  	int color;
	int offset;


	offset=0;
	digitalWrite(CLK, 1);//output_high(CLK);						// Idle state
	digitalWrite(CLK, 1);//output_high(CLK);
  	for (int i = 0;i<numpixels;i++)					// clock out this many dots
	{
		color=*(ptr+offset);
		if (color==0)
		{
			digitalWrite(PIXEL, 1);//output_high(PIXEL);				// pixel off
		}
		else
		{
			digitalWrite(PIXEL, 0);//output_low(PIXEL);
		}
		// Pixel clock - if this is not long enough we get noise on the display
		// unsure a few cycles low follwed by a few of high, try to avoid usleep as timer resolution is poor

		digitalWrite(CLK, 0);
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 0);
		digitalWrite(CLK, 1);
		digitalWrite(CLK, 1);
		digitalWrite(CLK, 1);
		digitalWrite(CLK, 1);
		digitalWrite(CLK, 1);
		digitalWrite(CLK, 1);
		/*output_low(CLK);					// clock pixel in
		output_low(CLK);
		output_low(CLK);
		output_low(CLK);
		output_low(CLK);
		output_low(CLK);
		output_high(CLK);
		output_high(CLK);
		output_high(CLK);					// Idle state
		output_high(CLK);					// Idle state
		output_high(CLK);					// Idle state
		output_high(CLK);					// Idle state
        */
			offset++;
   	}
}



//--------------------------------------------------------------
void testApp::draw(){

	ofBackground(100,100,100);
	ofSetHexColor(0xffffff);
	//vidGrabber.draw(20,20);
    vidGrabber.update();

        videoScale = 20;
        //cols = ofGetWidth() / videoScale;
        cols = camWidth / videoScale;
        //rows = ofGetHeight() / videoScale;
        rows = camHeight / videoScale;
		int totalPixels = camWidth*camHeight*3;

		//if (vidGrabber.isFrameNew()){
		unsigned char * pixels = vidGrabber.getPixels();

		/////// flip attempt
		for (int s = 0; s < 3 *camWidth; s+= 3){
            for (int t = 0; t < camHeight; t++){
                verticalFlip[(camHeight - t - 1) * 3 * camWidth + s] =     pixels[t * 3 * camWidth + s];
                verticalFlip[(camHeight - t - 1) * 3 * camWidth + s + 1] = pixels[t * 3 * camWidth + s + 1];
                verticalFlip[(camHeight - t - 1) * 3 * camWidth + s + 2] = pixels[t * 3 * camWidth + s + 2];

                //horizontalFlip[t * 3 * camWidth + 3 * (camWidth - 1) - s] = pixels[t * 3 * camWidth + s];
                //horizontalFlip[t * 3 * camWidth + 3 * (camWidth - 1) - s + 1] = pixels[t * 3 * camWidth + s + 1];
                //horizontalFlip[t * 3 * camWidth + 3 * (camWidth - 1) - s + 2] = pixels[t * 3 * camWidth + s + 2];

            }
		}


        //verticalFlipTexture.loadData(verticalFlip, camWidth, camHeight, GL_RGB);
        //horizontalFlipTexture.loadData(horizontalFlip, camWidth, camHeight, GL_RGB);



		/////// end flip attept
        //int counter = 0;
        int threshold = 160;

		for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j+=1) {
                if (i<16){
                xPos = j*videoScale*3;
                yPos = i*videoScale;
//                int r = (yPos*camWidth*3) + xPos;
//                int g = (yPos*camWidth*3) + (xPos+1);
//                int b = (yPos*camWidth*3) + (xPos+2);
//                int grayPixel = (11 * pixels[r] + 16 * pixels[g] + 5 * pixels[b]) / 32; //2805 + 4080 + 1275

                int loc = xPos + yPos * camWidth*3;

                if (verticalFlip[loc] > threshold) {
//                    videoInverted[counter] = 255;
//                    ofSetColor(255);
                    dotColor = 255;
                     pixelsB[i*j] ='1';
//                    whiteX = i;
//                    whiteY = j;
                } else {
//                    videoInverted[counter] = 0;
//                    ofSetColor(0);
                    dotColor = 0;
                     pixelsB[i*j] ='0';
                    //whiteY = i;
                }

                    // pixelsB[1] ='0';
                //ofFill();
                //ofCircle(i*20, j*20, 10, 10);

                //videoInverted[counter] = grayPixel;
                //ofCircle(whiteX, whiteY, 20, 20);
                //counter++;

                ofSetColor(dotColor);
                ofFill();
                //ofCircle(xPos, yPos, 20, 20);
                ofCircle(xPos/3 +25, yPos+25, videoScale/4, videoScale/4);

                myfont.drawString(ofToString(pixelsB[i*j]), xPos/3+15,yPos+365);

                }

            }
        }

	//videoTexture.draw(20+camWidth,20,camWidth,camHeight);
		//videoTexture.loadData(videoInverted, camWidth,camHeight, GL_LUMINANCE);


        //////////////////// BEGIN IMPORTED LOGIC /////////////////

  int i,x;
  int row=0;
  int chunk;

  // idle state for all lines
    digitalWrite(SCLK, 1);
 // output_high(SCLK);
    digitalWrite(CLK, 1);
 // output_high(CLK);
    digitalWrite(A, 0);
 // output_low(A);
    digitalWrite(B, 0);
 // output_low(B);
    digitalWrite(PIXEL, 0);
//  output_low(PIXEL);
    digitalWrite(OE, 1);
//  output_high(OE);


 // Adjust values, these values need to be 8 more to the right
 for (row=0;row<=3;row++)								// For each of the 4 sets of lines
 {
       	for (chunk=0;chunk<=16;chunk++)			 				// Values 0 to 63 tweaked
	{
		indexes[row][chunk]=indexes[row][chunk]+8;
	}
 }




       	//*********************************************************************************************************************
	for (row=0;row<=3;row++)							// For each of the 4 sets of lines
	{
		// One set of 4 panels is upside down relative to the other, so half the line data needs to clock in forwards half backwards
       		for (chunk=0;chunk<16;chunk++)						// 128 chunks in the 1024 pixels we need to clock in
		{
			 // imagebuf is pointer + offset extracted from array

			 	clock_pixels(pixelsB + (indexes[row][chunk]),8);

		}

		// this way round is best i think
		update_leds();								// Now we have 1024 pixels clocked in update the display
        select_row(row);							// Hmmm fails if I dont do this just before clocking each 1024 pixels ...

		usleep(3000);
	}
   }





/////////////////// END IMPORTED LOGIC ////////////////







//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	// in fullscreen mode, on a pc at least, the
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...

	// Video settings no longer works in 10.7
	// You'll need to compile with the 10.6 SDK for this
    // For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
    // http://forum.openframeworks.cc/index.php?topic=10343
	if (key == 's' || key == 'S'){
		vidGrabber.videoSettings();
	}


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
