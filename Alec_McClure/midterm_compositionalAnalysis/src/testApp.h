#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include <iostream>

#define max 5000
//max is the maximum number of lines and images, 5000 for what i was messing with


using namespace cv;
using namespace ofxCv;

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void generateLines();
		void imageSelect(), calcPixels(), averagePixels();
		void calcImageSelection(), calcAverage(), doAutomation(), reloadImages(), reloadImagesB();
		bool neverLines;

        bool init, refresh;
        int initVal;

		ofImage img;
		Mat src, cdst, dst, imgMat, bw, blurred;

		vector<Vec4i> lines;
		string titlez;
		//int threshold0, threshold1, threshold2;

		//bool showCanny, showOriginal, showLines, showCycle;

        //ofxCv::ofxCvGrayscaleImage grayscaleImg;
//		ofxCvGrayscaleImage greyImg;



        ofImage image[max];
        string imagePath[max], imagePathB[max], imagePathC[max], imagePathD[max];

        int imagesViewed();
        int imageCount, imagesViewCount;
        int imageSelection, oldSelection;
        ofPoint start[max][max], end[max][max];
        float angle[max][max];
        int averageAngle[max];
        //vector<float> angle;
        int parallelCount[max];
        //vector<float> parallels;
        //int modeCount;
        float dominantAnglePrevalence[max][4], dominantAngle[max];
        int modeSorted[max][4]; //top 5 frequencies
        int interModeFrequency[362];
        float interModeWeight[362];
        float interSpecial[362];


        int interDistinctiveAngleCount;
        float specialSort[362]; //top angles sorted by special score (sum(each angle occurance * each dominance )(


        ofxPanel mainGui, lineGui, pixelsGui, aestheticsGui, calcGui;
        ofxFloatSlider threshold0, threshold1, threshold2;//t0slider, t1slider, t2slider;
        ofxFloatSlider thresholdA, thresholdB, thresholdC, lineWidth;//t0slider, t1slider, t2slider;
        ofxIntSlider heatMapAlpha, blurAmount, angleTolerance, angleAverageThreshold;
        bool bHide;
        ofxToggle showCanny, showBlur, blurToggle, showOriginal, showLines, showCycle, heatMap, smoothToggle, redGlowToggle, oneShot;//, cannyToggle, linesToggle;
        ofxToggle fastMode, calcIndividual, calcTotal, heatMapB;
        ofxToggle automate, sortImages, sortImagesB, findPixels, findPixelsB;

        ofxLabel filename, framerate;

        //ofColor pixelColor[786432];
        //float redAverage;
        float redAverage[1024 * 683];
        float greenAverage[1024 * 683];
        float blueAverage[1024 * 683];
        ofColor pixelAverage[1024 * 683];
        int pixelAmount;


};
