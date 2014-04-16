#include "testApp.h"



/*
NOTES / TO DO:

4/1/14
other idea for manipulation: divide the width (or height) by the number of images and find that many pixel rows(or columns) from each image
    -perhaps each image could be rated and given that many

3/19/14

doh, just finished pixel color averaging and realized that i could have just drawn each image over each other with the alpha as 255 / imageCount

3/17/14

ok, now it orders images by top angle, then resorts by top dominant angle (undoing before)... need to make it consider both

3/15/14

currently only supports the top mode angle (interModeSorted[0])

basic sort is now working, simply based on primary angle-- need to now add in consideration of the actual dominance of the image

sorting some things led to repetition... why? ----- problem was tha tsome angles have the same dominance ratio; fixed by adding negligible amount to the end once one has been used

involve the top angles, not just the primary one


3/12/14 -- set the initial angle to something arbitrary like 361 so it can ignore those
look into drawing the lines with small ellipses with xeno interpolation



3/10/14

add something to highlight the individual angles when you hover over the line

finish total sorts and calcAverage()

fix the titles

clean up gui

figure out angle tolerance for averages -- some arent calculating well

change color of the circles at end points and make the diameter into a slider





3/4/14

Figure out how to scale images and make them comparable -- are portait and landscape images comparison compatible?
        e.g. if image y dimension > ofGetHeight, scale = 0.5

Create vector to store and compare all the different image vec4i

Find angle between 2 points, compare angles

Find length of lines from 2 points, compare lengths and parallel
    -most similar angles and the avg x/y point of them
    -most vertical/horizontal lines -> should indicate which images are taken from flattened perspective, most vertical lines = buildings?
    -most parallel lines = urban?, sort by angle/position
    -most lines?

    once sort function is chosen, then it reorders the photos

What is the average line angle?  Average line coordinate?

I could recognize so many of images... many vague feelings before confirmation
Also, I could recognize some scenes (e.g. subway car interior) even though I didn't recognize the photo

making sense of lines

PERFORMANCE:

too many images loaded = slow
running heat map = slow
only few images loaded = fast (unless heat map)
ofEnableSmoothing() = slow while drawing tons of lines i.e. heat map


*/



using namespace cv;
using namespace ofxCv;
cv::Mat src;
//--------------------------------------------------------------



void testApp::setup(){
    ofSetWindowTitle("Compositional Analysis Tool");
    //ofSetBackgroundAuto(false);
    refresh = true;



    threshold0 = 50;
    threshold1 = 50;
    threshold2 = 10;
    imagesViewCount = 1;
    //heatMap = false;
    showBlur = false;

    //showLines = true;
    //showOriginal = true;
    //howCycle = false;

    //ofImage img;



    string path = "jpg/";
    ofDirectory dir(path);
    //only show jpg files
    dir.allowExt("jpg");
    //populate the directory object
    dir.listDir();
    dir.sort();
    imageCount = dir.numFiles() - 1;


    cout << "Image count total = " << imageCount << endl;
    cout << "Image selection is: " << imageSelection << endl;


    //go through and print out all the paths
    for(int i = 0; i < dir.numFiles(); i++){
        //ofLogNotice(dir.getPath(i));
        imagePath[i] = dir.getPath(i);
        image[i].loadImage(dir.getPath(i));
        cout << dir.getPath(i) << endl;

        }

    //img.loadImage(image[]);

    //imgMat = toCv(image[imageSelection]);



    mainGui.setup();
    mainGui.setName("System");
	mainGui.add(filename.setup("",imagePath[imageSelection]));
    mainGui.add(framerate.setup("framerate", ofToString(ofGetFrameRate())));
    mainGui.add(fastMode.setup("fast mode", false));
	mainGui.add(showCycle.setup("cycling", false));
    mainGui.add(oneShot.setup("export pdf", false));

    pixelsGui.setup();
    pixelsGui.setName("Image Layer Actions");
    pixelsGui.setPosition(ofGetWidth()-220, 10);
    pixelsGui.add(findPixels.setup("pixels averaged(old)", false));
    pixelsGui.add(findPixelsB.setup("layer images equally", false));

    lineGui.setup();
    lineGui.setPosition(10,160);
    lineGui.setName("Edge/Line Detection");
	lineGui.add(thresholdA.setup("cannyThreshold1", 50, 1, 1000));
	lineGui.add(thresholdB.setup("cannyThreshold2", 200, 1, 1000));

	lineGui.add(threshold0.setup("minIntersections", 50, 1, 500));
	lineGui.add(threshold1.setup("minLinLength", 50, 1, 1000));
	lineGui.add(threshold2.setup("maxLineGap", 10, 1, 400));

	lineGui.add(blurToggle.setup("preprocess blur", true));
	lineGui.add(blurAmount.setup("blur amount", 4, 1, 20));
	//gui.add(showBlur.setup("show blur", false));

    aestheticsGui.setup();
    aestheticsGui.setPosition(10, 330);
    aestheticsGui.setName("Appearance");
	aestheticsGui.add(lineWidth.setup("line width", 2.5, 1, 10));
	aestheticsGui.add(showOriginal.setup("show image", true));
	aestheticsGui.add(showCanny.setup("show edges", false));
	aestheticsGui.add(showLines.setup("show lines", true));
	aestheticsGui.add(heatMap.setup("show heat map", false));
	aestheticsGui.add(heatMapB.setup("show heat map points", false));
	aestheticsGui.add(heatMapAlpha.setup("heat map alpha", 20, 1, 255));
	aestheticsGui.add(smoothToggle.setup("smooth", true));
	aestheticsGui.add(redGlowToggle.setup("red glow", true));


    //gui.add(angleTolerance.setup("angle tolerance", 0, 0, 100));
	//gui.add(angleAverageThreshold.setup("interangle threshold", 0, 0, 4));
	calcGui.setup();
	calcGui.setPosition(10, 550);
	calcGui.setName("Line Calculations");
    calcGui.add(calcIndividual.setup("calc single", false));
    calcGui.add(calcTotal.setup("calc total viewed", false));
    calcGui.add(automate.setup("automate calculations", false));
    calcGui.add(sortImages.setup("sort by total dominance", false));
    calcGui.add(sortImagesB.setup("sort by mode/dominance", false));

	bHide = true;
	init = true;
	initVal = 1;
	heatMap = false;
	angleAverageThreshold = 0;

	//imageSelection = 0;
	//oldSelection = 100;

	//ofEnableSmoothing();
    imageSelect();


}

//--------------------------------------------------------------
void testApp::update(){

}



//--------------------------------------------------------------
void testApp::draw(){
    filename = imagePath[imageSelection];


	if( oneShot ){
		ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
	}




 //   else { init = false;}

if (refresh == true || fastMode == false){
    framerate = ofToString(ofGetFrameRate());


    ofBackground(10,10,10);
    ofSetLineWidth(lineWidth);

    if (smoothToggle){
        ofEnableSmoothing();
    } else {
        ofDisableSmoothing();
    }

    if (showCycle){
        if (imageSelection < imageCount) {
            imageSelection++;
            imagesViewed();
        } else {
            imageSelection = 0;
        }
        //imgMat = toCv(image[imageSelection]);
        imageSelect();

        cout << "CYCLING -- SELECTION IS: " << imageSelection << endl;
    }



    //drawMat(src, 0, 0);
    //drawMat(imgMat, 0, 0);
    ofSetColor(255,255,255);
    //drawMat(dst, 0, 0);

    if (showOriginal) {
        drawMat(imgMat, 0, 0);
    }


    cvtColor(imgMat, bw, COLOR_RGB2GRAY);

    if (blurToggle){
        blur( bw, blurred, Size(blurAmount,blurAmount) );
        } else {
        bw = blurred;
        cout << "blur bypassed son" << endl;
    }
    if (showBlur){
        drawMat(blurred, 0, 0);
    }

    Canny(blurred, dst, thresholdA, thresholdB, 3);

    //Canny(imgMat, dst, 50, 200, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);

    if (showCanny){
        drawMat(dst, 0, 0);}

    //vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/180, threshold0, threshold1, threshold2 );
    //ofSetLineWidth(3);


    if (heatMap) {

        //ofDisableSmoothing();
        if (heatMapAlpha < 255){
        ofSetColor(0,0,255,heatMapAlpha);
        } else {
        ofSetColor(0,0,255);
        cout << "is it faster?" << endl; //attempt to improve performance by not drawing alpha, but it didnt work
        }


        for (int x = 0; x < imagesViewCount; x++){
            for (int z = 0; z < max; z++){
                ofLine(start[x][z], end[x][z]);
            }
        }
    } else {
        ofSetColor(255,0,0);
        //ofEnableSmoothing();
    }

    if (heatMapB) {
           ofSetColor(0,0,255,heatMapAlpha);


        for (int x = 0; x < imagesViewCount; x++){
            for (int z = 0; z < max; z++){
                ofCircle(start[x][z], 5);
                ofCircle(end[x][z], 5);
            }
        }



    } else {
        ofSetColor(255,0,0);
        //ofEnableSmoothing();
    }


    generateLines();

    if (calcIndividual) { //
        calcImageSelection();
    }

    if (calcTotal){
        calcAverage();

    }


    refresh = false;
    }

    if (automate){

    /* OLD AUTOMATE THAT WORKS FINE
        redGlowToggle = false;
        doAutomation();
        calcAverage();
        cout << " DONE AUTOMATING -- JESUS CHRIST, FINALLY!" << endl;
        automate = false;
    */

    }

    if(sortImages){
        redGlowToggle = false;
        doAutomation();
        calcAverage();
        cout << " DONE AUTOMATING -- JESUS CHRIST, FINALLY!" << endl;

        reloadImages();
        doAutomation();
        calcAverage();
    }

    if(sortImagesB){
        //doAutomation();
        //calcAverage();
        //reloadImages();


        //reloadImagesB();


        redGlowToggle = false;
        doAutomation();
        calcAverage();
        cout << " DONE AUTOMATING -- JESUS CHRIST, FINALLY!" << endl;

        reloadImages();
        doAutomation();
        calcAverage();

        reloadImagesB();
        doAutomation();
        calcAverage();

        automate = false;
    }

    if(findPixels){
        calcPixels();
    }

    if(findPixelsB){

        averagePixels();
    }


    if( oneShot ){
		ofEndSaveScreenAsPDF();
		oneShot = false;
	}

    if (bHide) {
        mainGui.draw();
        lineGui.draw();
        aestheticsGui.draw();
        calcGui.draw();
        pixelsGui.draw();
    }

//fade in for app
    if (initVal < 256){
        ofSetColor(10,10,10,255-initVal);
        ofRect(0,0,ofGetWidth(), ofGetHeight());
        initVal += 4;
        refresh = true;}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //ofClamp(threshold0, 1, 1000);
    //ofClamp(threshold1, 0, 1000);
    //ofClamp(threshold2, 0, 1000);

    switch (key) {
        /*case 'q' :
            threshold0 += 1;
            break;
        case 'w' :
            if (threshold0 > 1) {
                threshold0 -= 1;}
            break;
        case 'a' :
            threshold1 += 1;
            break;
        case 's' :
            if (threshold1 > 0){
                threshold1 -= 1;}
            break;
        case 'z' :
            threshold2 += 1;
            break;
        case 'x' :
            if (threshold2 > 0) {
                threshold2 -= 1;}
            break;*/
        case 'e' :
            showCanny = !showCanny;
            break;
        case 'd' :
            showOriginal = !showOriginal;
            break;
        case 'c' :
            showLines = !showLines;
            break;
        case 'r' :
            showCycle = !showCycle;
            break;
        case 'f' :
            heatMap = !heatMap;

        case 'b' :
            blurToggle = !blurToggle;
            break;
        case 'p' :
            calcIndividual = !calcIndividual;
            break;
        case 'h' :
            mainGui.setPosition(10,10);

            lineGui.setPosition(10,160);
            pixelsGui.setPosition(ofGetWidth()-220, 10);
            aestheticsGui.setPosition(10, 330);
            calcGui.setPosition(10, 550);

            bHide = !bHide;
            break;

        case '0' :
            findPixelsB = !findPixelsB;
            break;

        case 's' :
            //gui.saveToFile("settings.xml");
            //cout << "SETTINGS SAVED TO \"settings.xml\"" << endl;
            oneShot = true;
            cout << "EXPORTING PDF... SLOWLY..." << endl;
            break;
        case 'l' :
            lineGui.loadFromFile("settings.xml");
            cout << "SETTINGS LOADED FROM \"settings.xml\"" << endl;
            break;
    }
/*
    cout << "threshold0: "<<threshold0 <<endl;
    cout << "threshold1: "<<threshold1 <<endl;
    cout << "threshold2: "<<threshold2 <<endl << endl;
*/



    if (key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
        if (key == OF_KEY_LEFT){
            if (imageSelection > 0){
                imageSelection -= 1;
            } else {
                imageSelection = imageCount;
            }
        }
        if (key == OF_KEY_RIGHT){
            if (imageSelection < imageCount){
                imageSelection += 1;
            } else {
                imageSelection = 0;
            }
            imagesViewed();
        }
        imageSelect();//imgMat = toCv(image[imageSelection]);


        for (int i = 0; i <= angleAverageThreshold; i++){
            cout << "modeSorted for image " << imageSelection << " / mode number " << i << " is:   "<<modeSorted[imageSelection][i]<< " dominantAnglePrev: " <<dominantAnglePrevalence[imageSelection][i] << endl;
        }
    }

    refresh = true;
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
    refresh = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    refresh = true;
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


int testApp::imagesViewed(){
    if (imagesViewCount <= imageCount){
    imagesViewCount += 1;}

    return imagesViewCount;
}

void testApp::generateLines(){
    for (int i = 0; i < max; i++){
        angle[imageSelection][i] = 361;
    }

    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        //line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
        //ofPoint start, end;
        start[imageSelection][i].set(l[0], l[1]);
        end[imageSelection][i].set(l[2], l[3]);
        if (showLines){
            if (heatMap){
                ofSetColor(255,255,255);//,240);
            } else {
                ofSetColor(255,0,0);}//, 240);}

            //if (imageSelection != oldSelection || init == true){
                ofLine(start[imageSelection][i], end[imageSelection][i]); //draw lines for current selection
                angle[imageSelection][i] = atan2(start[imageSelection][i].y - end[imageSelection][i].y, start[imageSelection][i].x - end[imageSelection][i].x);
                angle[imageSelection][i] = angle[imageSelection][i] * 180 / PI;
                //cout << "initial is " << angle[imageSelection][i] << " start is " << start[imageSelection][i] << " end is " << end[imageSelection][i] << endl;
                //cout << angle[imageSelection][i] * 180 / PI << endl;
//                cout<<angle[imageSelection].length<<endl;

                if (redGlowToggle){
                    ofSetColor(255, 0, 0, 100);
                    ofLine(start[imageSelection][i] -1, end[imageSelection][i] -1);
                    ofLine(start[imageSelection][i] +1, end[imageSelection][i] +1);
                    ofSetColor(255, 0, 0, 50);
                    ofLine(start[imageSelection][i] -2, end[imageSelection][i] -2);
                    ofLine(start[imageSelection][i] +2, end[imageSelection][i] +2);
                    ofSetColor(255, 0, 0, 30);
                    ofLine(start[imageSelection][i] -3, end[imageSelection][i] -3);
                    ofLine(start[imageSelection][i] +3, end[imageSelection][i] +3);
                    ofSetColor(255, 0, 0, 30);
                    ofLine(start[imageSelection][i] -4, end[imageSelection][i] -4);
                    ofLine(start[imageSelection][i] +4, end[imageSelection][i] +4);
                    ofSetColor(255, 0, 0, 30);
                    ofLine(start[imageSelection][i] -5, end[imageSelection][i] -5);
                    ofLine(start[imageSelection][i] +5, end[imageSelection][i] +5);
                }
            //oldSelection = imageSelection;
            //}
        }

        //return angle[imageSelection][i];
    }


}

void testApp::imageSelect(){

        imgMat = toCv(image[imageSelection]);
}

void testApp::calcImageSelection(){
    //first sort the parallels

//int ii;
  //  int jj;
    float tmp;

//for (int i = 0; i < max ){
//averageTotal[imageSelection] = 0;}



//FIND AVERAGE ANGLE -- not very useful, must find mode
    float average = 0;
    float averageCount = 0;
    for(int z = 0; z < max; z++){
        if (angle[imageSelection][z] < 0) {
            angle[imageSelection][z] += 360; //convert negative angles into angle/360
        }
        //angle[imageSelection][z] -= 90; //convert points to 0-180 with 0 at the top of a circular compass

        if ((angle[imageSelection][z] != 361) && ((start[imageSelection][z].x != 0) && ((start[imageSelection][z].y != 0) ))) {
            //cout<< z<<" is " << angle[imageSelection][z] << " start is " << start[imageSelection][z] << " end is " << end[imageSelection][z] << endl;
            average += angle[imageSelection][z];
            averageCount++;

        }
    }

    averageAngle[imageSelection] = average / averageCount;
    cout<< "Image " << imageSelection << " mean angle is " << averageAngle[imageSelection] << endl;

//SORT
    for(int ii = 0; ii < averageCount; ii++) // arraylength is the length of the array you want to use
    {
        for(int jj = ii + 1; jj < averageCount; jj++) // j will always be after i
        {
            // array is the array itself
            if(angle[imageSelection][ii] > angle[imageSelection][jj]) // check to see if it is larger than the other one
            {
                // if so then swap them
                tmp = angle[imageSelection][jj];
                angle[imageSelection][jj] = angle[imageSelection][ii];
                angle[imageSelection][ii] = tmp;
            }
        }
        //cout << ii << " sort is " << angle[imageSelection][ii]<< endl;
    }


//FIND MODE ANGLE



    int modeFrequency[360];



    for (int j = 0; j < 360; j++){ //setting everything to 0
        modeFrequency[j] = 0;

        if (j < 5){
            modeSorted[imageSelection][j] = 361;
        }
    }
    for (int xx = 0; xx < averageCount; xx++){ //xx is each line in given imageSelection


        if (int(angle[imageSelection][xx]) == int(angle[imageSelection][xx+1])){ //this is the old line before adding angleTolerance
        //if ( int(angle[imageSelection][xx]) <= int(angle[imageSelection][xx+1]) + angleTolerance){ //failed attempt at adding angle tolerance ... doesnt work because of if statement doesnt check a range, only the next one... needs to be for loop cycling through all of them
            //cout<<"angle same as next angle"<<endl;

            modeFrequency[int(angle[imageSelection][xx])] += 1;

            //cout<<"current angle: " << angle[imageSelection][xx] << "   frequency: " << modeFrequency[int(angle[imageSelection][xx])] + 1 << endl; //the frequency of given mode plus the original
        } else {
            //cout<<"angle is not the same"<<endl;
        }


    }

//sort mode frequencies
//should mode frequency comparisons be based on most frequent angle with a minimum frequency of maybe 5 or 10?
//if modeFrequency[imageSelection][j] == modeFrequency[max][j] they have the same most common angle
//then find out what the minimum

//also find top angle ratio to total angles

    //int
    for (int j = 0; j < 360; j++){
        //for (int k = j+1; k < 360; k++);
            //if (modeFrequency[j] > modeFrequency[k]) {
            if (modeFrequency[j] > 0){
                //cout<<"Angle " << j << " has a frequency of " << modeFrequency[j]<<endl;
                //tmp = modeFrequency[k];
                //modeFrequency[k]
    //            if frequency of next mode is greater than previous mode, assign previously top mode to 2nd, 2nd to third
                if (modeFrequency[j] >= modeFrequency[modeSorted[imageSelection][0]]) {
                    modeSorted[imageSelection][4] = modeSorted[imageSelection][3];
                    modeSorted[imageSelection][3] = modeSorted[imageSelection][2];
                    modeSorted[imageSelection][2] = modeSorted[imageSelection][1];
                    modeSorted[imageSelection][1] = modeSorted[imageSelection][0];
                    modeSorted[imageSelection][0] = j;//modeFrequency[j];
                } else if (modeFrequency[j] >= modeFrequency[modeSorted[imageSelection][1]]){
                    modeSorted[imageSelection][4] = modeSorted[imageSelection][3];
                    modeSorted[imageSelection][3] = modeSorted[imageSelection][2];
                    modeSorted[imageSelection][2] = modeSorted[imageSelection][1];
                    modeSorted[imageSelection][1] = j;//modeFrequency[j];

                } else if (modeFrequency[j] >=  modeFrequency[modeSorted[imageSelection][2]]){
                    modeSorted[imageSelection][4] = modeSorted[imageSelection][3];
                    modeSorted[imageSelection][3] = modeSorted[imageSelection][2];
                    modeSorted[imageSelection][2] = j;//modeFrequency[j];

                } else if (modeFrequency[j] >=  modeFrequency[modeSorted[imageSelection][3]]){
                    modeSorted[imageSelection][4] = modeSorted[imageSelection][3];
                    modeSorted[imageSelection][3] = j;//modeFrequency[j];

                } else if (modeFrequency[j] >=  modeFrequency[modeSorted[imageSelection][4]]){
                    modeSorted[imageSelection][4] = j;//modeFrequency[j];

                }

            }
    } //first find the most common angles themselves and then find the associated frequency

    cout << "top modes: " << modeSorted[imageSelection][0] << "," << modeSorted[imageSelection][1] << "," << modeSorted[imageSelection][2] << "," << modeSorted[imageSelection][3] << "," << modeSorted[imageSelection][4] << endl;

    //find top angle prevelance ratio within a given image

    for (int i = 0; i < 5; i++){
        dominantAnglePrevalence[imageSelection][i] = modeFrequency[modeSorted[imageSelection][i]]/ averageCount;
        dominantAngle[imageSelection] = modeSorted[imageSelection][0]; //indexes the most common angle for this image

        cout << "dominant angle " << i <<" (" << modeSorted[imageSelection][i] << ") is " << dominantAnglePrevalence[imageSelection][i] << endl;
    }


    calcIndividual = false;


}


void testApp::calcAverage(){
//find most common angle to find some kind of most average image
//can then cycle through to least similar -> so if angle 180 is mode angle, things that are closest to mode angle with highest dominanceRatio are next

//arrange the photos by angle (e.g. 10, 10, 20, 90, 90, 90, 120, etc.  the tie breakers would be based on highest dominanceRatio


//also can arrange photos by how dominant dominantRatio is


//first cycle through modeSorted[i(imageSelection)][0-x(threshold)] and total findings

/*
for (int i = 0; i < imageCount; i++){
    for (int j = 0; j < angleAverageThresold; j++){
        modeSorted[i][j]
        interModeFrequency[j]
    }

}
*/
    cout<< " calcAverage function running" <<endl;


    //int modeFrequency[max];
    //angleAverageThreshold = 0;



    for (int j = 0; j < 362; j++){ //setting everything to 0, using 362 since 361 is the ones that are nothing
        interModeFrequency[j] = 0;
        interModeWeight[j] = 0;


    }


    for (int i = 0; i <= imageCount; i++){
        for (int xx = 0; xx <= angleAverageThreshold; xx++){ //xx is each top angle (0-4) in given imageSelection
            interModeFrequency[modeSorted[i][xx]] = 1;  // the frequency for all is one... this also restarts the count when it comes up again
            interModeWeight[modeSorted[i][xx]] = dominantAnglePrevalence[i][xx];
            interSpecial[modeSorted[i][xx]] = 1 * dominantAnglePrevalence[i][xx];
            for (int j = 0; j <= imageCount; j++){;


                    if ((modeSorted[i][xx] == modeSorted[j][xx]) && (modeSorted[i][xx] != 361) && (i != j)){ //this is the old line before adding angleTolerance

                        interModeFrequency[modeSorted[i][xx]] += 1;
                        interModeWeight[modeSorted[i][xx]] += dominantAnglePrevalence[j][xx];
                        interSpecial[modeSorted[i][xx]] += 1 * dominantAnglePrevalence[j][xx];


                       //cout<<"current interImage: " << i << " Interangle: " << modeSorted[i][xx] << " frequency: " << interModeFrequency[modeSorted[i][xx]] + 1 << "dominance: " << interModeWeight[modeSorted[i][xx]]<< endl; //the frequency of given mode plus the original
                    } else {
                        //cout<<"inter angle " << i << " is not the same as "<< j <<endl;
                    }

            }
        }
    }

    for (int j = 0; j <= imageCount; j++){ // this is just a debug loop to compare modesorted to the counts below
        for (int i = 0; i <= angleAverageThreshold; i++){
            cout << "modeSorted for image " << j << " / mode number " << i << " is:   "<<modeSorted[j][i]<< " dominantAnglePrev: " << dominantAnglePrevalence[j][i] << endl;
        }
    }

    interDistinctiveAngleCount = 0;

    for (int i = 0; i < 360; i++){

        if (interModeFrequency[i] > 0) {

            interDistinctiveAngleCount +=1;
            interModeWeight[i] = interModeWeight[i] / interModeFrequency[i]; //first make the weight an average of all the mode occurances at that angle

            cout<<"current interAngle: " << i << " interfrequency: " <<interModeFrequency[i] << " interModeWeight Average: " << interModeWeight[i]<<endl;
            cout << "interSpecial: " << interSpecial[i]<<endl;


        }
            specialSort[i] = interSpecial[i];
    }






    //now sort them by special score
     // interSpecial = that angle's special score, specialSort = that angle ordered
    for (int i = 0; i < 360; i++){
        for (int j = 0; j < 360; j++){
       //if (specialSort[i] != 0){
            if (specialSort[i] >= specialSort[j]){
                float container = specialSort[i];
                specialSort[i] = specialSort[j];
                specialSort[j] = container;

            }
        }
    }
    /*for (int i = 0; i < 360; i++){
        cout << i << "(i) is " << specialSort[i] << endl;
    }*/


    for (int i = 0; i < 360; i++){
    for (int j = 0; j < 360; j++){
        if (specialSort[i] == interSpecial[j]){ //convert specialSort from the special score to the actual angle
            interSpecial[j] += .000001; //try to differentiate them against several angles having the same value
            specialSort[i] = j;
        }
    }
    }
    //interDistinctiveAngleCount += 1;
    specialSort[interDistinctiveAngleCount] = 361;
    cout<< "There are " << interDistinctiveAngleCount << " different dominant angles to sort."<<endl;

    cout<<"The top angles by special score are: ";
    for(int i = 0; i <= interDistinctiveAngleCount; i++){
            cout << specialSort[i] << ", ";

    }
    cout << endl;




    calcTotal = false;


}


void testApp::reloadImages(){
//reload the images based on the calculations

//if the dominant angle matches the specialSort, then move it up

    int currentPosition = 0;
    int pathOrder[imageCount];
    float tempDom[imageCount], newDom[imageCount];

    for (int i = 0; i <=imageCount; i++){
        cout<< "image " << i << " presorted path is " <<  imagePath[i] << " angle: " <<dominantAngle[i] << " domAnglePrev: " << dominantAnglePrevalence[i][0] << endl;
        pathOrder[imageCount] = 0;
        tempDom[imageCount] = 0;
        newDom[imageCount] = 0;
    }


    for (int i = 0; i <= interDistinctiveAngleCount; i++){ // i is current top angle, like 0-180, 1-90, 2-150, etc.
        for (int j = 0; j <= imageCount; j++){
       // for (int k = 0; k <= imageCount; k++){
            if (dominantAngle[j] == specialSort[i]){
                //move forward
                cout<<"Angle # " << i << "  " << specialSort[i] <<" Image # " << j << "  " << dominantAngle[j] << " current position = "<< currentPosition << endl;

             /*   if (dominantAnglePrevalence[j][i] >= dominantAnglePrevalence[k][i]){
                    string container = imagePath[currentPosition];
                    imagePath[currentPosition] = imagePath[j];
                    imagePath[j] = container;
                }
*/
                imagePathB[currentPosition] = imagePath[j];
                //imagePathC[currentPosition] = imagePath[j];
                tempDom[currentPosition] = dominantAnglePrevalence[j][0];
                newDom[currentPosition] = dominantAnglePrevalence[j][0];



                currentPosition++;
            }
        //}
        }
    }
    /*for (int i = 0; i <= imageCount; i++){ //ANOTHER TEST, at this stage, its still correct
        cout<< "newDom[" << i <<"] = " << newDom[i] << " tempDom["<<i<<"] = " << tempDom[i] <<endl;

    }*/

    float spacer = 0.000001;

        for (int i = 0; i <= imageCount; i++){
            for (int j = 0; j <= imageCount; j++){
                if ((newDom[i] == newDom[j] ) && (i != j)){
                        tempDom[j] += spacer;
                        newDom[j] += spacer;
                        spacer  += .000001;
                        cout << "added some to "<<i<< "  dom = " << newDom[j] <<endl;

                }
            }
        }

    /*for (int i = 0; i <= imageCount; i++){ //ANOTHER TEST, at this stage, its still correct
        cout<< "newDom2[" << i <<"] = " << newDom[i] << " tempDom2["<<i<<"] = " << tempDom[i] <<endl;

    }*/


    currentPosition = 0;
    for (int i = 0; i <= interDistinctiveAngleCount; i++){ // i is current top angle, like 0-180, 1-90, 2-150, etc.
        for (int j = 0; j <= imageCount; j++){
            for (int k = 0; k <= imageCount; k++){
                //if (dominantAngle[j] == specialSort[i]){
                    //move forward
                   // cout<<"Angle # " << i << "  " << specialSort[i] <<" Image # " << j << "  " << dominantAngle[j] << " current position = "<< currentPosition << endl;

                    if (newDom[j] >= newDom[k]){
                        float container = newDom[j];
                        newDom[j] = newDom[k];
                        newDom[k] = container;
                    }

                    //imagePathB[currentPosition] = imagePath[j];
                    }
                //}
        }
    }
    for (int i = 0; i < imageCount; i++){
        cout << "debug temp dom = " << tempDom[i] << "  ordered dom = " << newDom[i] << endl;
        cout << "imagePathB     = " << imagePathB[i] << endl;
    }




    for (int i = 0; i <=imageCount; i++){ //change to new path
        for (int j = 0; j <= imageCount; j++){


            if (newDom[i] == tempDom[j]){
                    imagePathC[i] = imagePathB[j];
                    cout << "sort -- imagePathB " << j << " " << imagePathB[j] << " becomes " << i << endl;

            }

        }
    }





    for (int i = 0; i <=imageCount; i++){
        cout<< "image " << i << " sorted path C is " <<  imagePathC[i] <<  " newDom is " << newDom[i]<<endl;
       // dominantAnglePrevalence[i][0] = newDom[i];

        //image[i].loadImage(imagePathB[i]);
        imagePath[i] = imagePathC[i];
        imagePathD[i] = imagePathC[i];
        image[i].loadImage(imagePathC[i]);
    }

    cout<<"RUN AUTOMATE CALCULATIONS AGAIN TO UPDATE FOR NEW SORT ORDER"<<endl;
    sortImages = false;
}





void testApp::reloadImagesB(){
//reload the images based on the calculations

//if the dominant angle matches the specialSort, then move it up

    int currentPosition = 0;
    int pathOrder[imageCount];
    float tempDom[imageCount], newDom[imageCount];

    for (int i = 0; i <=imageCount; i++){
        cout<< "image " << i << " presorted path is " <<  imagePath[i] << " angle: " <<dominantAngle[i] << " domAnglePrev: " << dominantAnglePrevalence[i][0] << endl;
        pathOrder[imageCount] = 0;
        tempDom[imageCount] = 0;
        newDom[imageCount] = 0;
    }


    for (int i = 0; i <= interDistinctiveAngleCount; i++){ // i is current top angle, like 0-180, 1-90, 2-150, etc.
        for (int j = 0; j <= imageCount; j++){
       // for (int k = 0; k <= imageCount; k++){
            if (dominantAngle[j] == specialSort[i]){
                //move forward
                cout<<"Angle # " << i << "  " << specialSort[i] <<" Image # " << j << "  " << dominantAngle[j] << " current position = "<< currentPosition << endl;

             /*   if (dominantAnglePrevalence[j][i] >= dominantAnglePrevalence[k][i]){
                    string container = imagePath[currentPosition];
                    imagePath[currentPosition] = imagePath[j];
                    imagePath[j] = container;
                }
*/
                imagePathD[currentPosition] = imagePathC[j];
                //imagePathC[currentPosition] = imagePath[j];
                tempDom[currentPosition] = dominantAnglePrevalence[j][0];
                newDom[currentPosition] = dominantAnglePrevalence[j][0];



                currentPosition++;
            }
        //}
        }
    }

        float spacer = 0.000001;

        for (int i = 0; i <= imageCount; i++){
            for (int j = 0; j <= imageCount; j++){
                if ((newDom[i] == newDom[j] ) && (i != j)){
                        tempDom[j] += spacer;
                        newDom[j] += spacer;
                        spacer  += .000001;
                        cout << "added some to "<<i<< "  dom = " << newDom[j] <<endl;

                }
            }
        }

    for (int i = 0; i <=imageCount; i++){
        cout<< "image " << i << " sorted path is " <<  imagePathD[i] <<  " newDom is " << newDom[i]<<endl;
       // dominantAnglePrevalence[i][0] = newDom[i];

        //image[i].loadImage(imagePathB[i]);
        //imagePath[i] = imagePath[i];
        image[i].loadImage(imagePathD[i]);
    }

    cout<<"RUN AUTOMATE CALCULATIONS AGAIN TO UPDATE FOR NEW SORT ORDER"<<endl;
    sortImagesB = false;
}

void testApp::doAutomation(){


         //imageSelection = 0;//start at the beginning
         imagesViewCount = 0;

        for (int i = 0; i <= imageCount; i++){ //cycle through and process each image
            imageSelection = i;
            imageSelect();
            imagesViewed();

            if (showOriginal) {
                drawMat(imgMat, 0, 0);
            }

            cvtColor(imgMat, bw, COLOR_RGB2GRAY);

            if (blurToggle){
                blur( bw, blurred, Size(blurAmount,blurAmount) );
                } else {
                bw = blurred;
            }

            Canny(blurred, dst, thresholdA, thresholdB, 3);

            //Canny(imgMat, dst, 50, 200, 3);
            cvtColor(dst, cdst, COLOR_GRAY2BGR);

            if (showCanny){
                drawMat(dst, 0, 0);}

            //vector<Vec4i> lines;
            HoughLinesP(dst, lines, 1, CV_PI/180, threshold0, threshold1, threshold2 );
            //ofSetLineWidth(3);


            generateLines();

            calcImageSelection();
        }
}

void testApp::averagePixels(){
    //bHide = false;

    mainGui.setPosition(-2000, -2000); // send these off screen so they dont interfere
    lineGui.setPosition(-2000, -2000);
    pixelsGui.setPosition(-2000, -2000);
    aestheticsGui.setPosition(-2000, -2000);
	calcGui.setPosition(-2000, -2000);

    //fastMode = true;

    ofSetBackgroundAuto(false);
    showOriginal = false;
    showLines = false;

    // METHOD 1
/*
    ofEnableAlphaBlending();
    float alpha = 255 / imageCount;
    ofSetColor(255,255,255, alpha);
    image[imageSelection].draw(0,0);
    //image[imageSelection]->draw();
    ofDisableAlphaBlending();
    cout << "drawing image " << imageSelection << endl;
*/

    //METHOD 2, divides evenly as it goes along

    for (int i = 0; i < imageSelection; i++){
        ofEnableAlphaBlending();
        float alpha;
        if (imageSelection > 0){
                alpha = 255 / float(imageSelection);
        } else {
            alpha = 255; //start the first image at full opacity
        }

        if (alpha < 1) {
            alpha = 1; //oF doesnt seem to support actual float values, as the opacity goes to zero for numbers between 0 and 1
        }
        ofSetColor(255,255,255, alpha);
        image[i].draw(0,0);
        //image[imageSelection]->draw();
        //ofDisableAlphaBlending();
        cout<< " alpha is " << alpha << endl;
    }
    cout << "drawing image " << imageSelection << endl;


        //image[imageSelection].draw(0,0);

    if (imageSelection <= imageCount){
    //for (int i = 0; i <= imageCount; i++){
        //image[i].draw(0,0,ofGetWidth(), ofGetHeight());
        imageSelection++;
    } else {
        fastMode = true;
        findPixelsB = false;
        cout << "TURNING OFF AVERAGING"<<endl;
    }

    //ofSetBackgroundAuto(false);



}
void testApp::calcPixels(){
/*
    for (int i = 0; i <= imageCount; i++){
        //ofPixels pix;
        unsigned char * pixels = image[i].getPixels();
    }
    for (int i = 0; i <= imageCount; i++){
        for (int xx = 0; xx < pixels[i].size; xx++){
            for (int yy = 0; yy < pixels[i].size
            ofColor pixColor[i][xx*yy] = pixels.getColor(xx, yy);

        }
    }
*/

    //ofColor pixelColor[imageCount][int(image[0].getWidth() * image[0].getHeight())];
    //ofColor pixelColor[imageCount][1024*768];
    //float cGreen[imageCount][image[0].width * image[0].height];
    //float cBlue[imageCount][image[0].width * image[0].height];

/*
    float redAverage[image[0].width * image[0].height];
    float greenAverage[image[0].width * image[0].height];
    float blueAverage[image[0].width * image[0].height];
    */

    pixelAmount = image[0].width * image[0].height;

    for (int i = 0; i < pixelAmount; i++){
        redAverage[i] = 0;
        greenAverage[i] = 0;
        blueAverage[i] = 0;
        pixelAverage[i].set(0,0,0);
    }

    for (int z = 0; z <= imageCount; z++){

        int w = image[z].getWidth();
        int h = image[z].getHeight();

        if (w != 1024 || h != 683){
            cout << "BROKEN SIZE"<<endl;
        }


        int type = image[z].type;
        int bpp = image[z].bpp / 8;
        unsigned char * pixels = image[z].getPixels();
        for (int i = 0; i < w; i++){
            for (int j = 0; j < h; j++){

                if(bpp >= 3){
                    float cRed = pixels[(j*w+i)*bpp+0];
                    float cGreen = pixels[(j*w+i)*bpp+1];
                    float cBlue = pixels[(j*w+i)*bpp+2];

                    redAverage[j*w+i] += cRed;
                    greenAverage[j*w+i] += cGreen;
                    blueAverage[j*w+i] += cBlue;

                    if(bpp >= 4){
                        float cAlpha = pixels[(j*w+i)*bpp+3];
                        cout << "BROKEN ALPHA"<<endl;
                    }
                    //pixelColor[z][j*w+i].set(cRed, cGreen, cBlue);
                    //cout<<"image- " << z << " column- " << i << " row- " << j << "Color(" << cRed <<", " << cGreen <<", " << cBlue << ")" << endl;

                }
                else if(bpp == 1){
                    float cGray = pixels[(j*w+i)];

                    cout << "BROKEN GRAY"<<endl;
                } else {
                    cout << "BROKEN NOTHING"<<endl;
                }

           }
        }
    }
    cout << "done pixelling" << endl;



    for (int i = 0; i < pixelAmount; i++){
        redAverage[i] = redAverage[i] / imageCount;
        greenAverage[i] = greenAverage[i] / imageCount ;
        blueAverage[i] = blueAverage[i] / imageCount;
        pixelAverage[i].set(redAverage[i], greenAverage[i], blueAverage[i]);
    }

    cout << "average red for pixel 0 =" << redAverage[0] << " average green = " << greenAverage[0] << " average blue = " << blueAverage[0] << endl;
    //test output

    cout << "sizeof pixelAverage = " << pixelAmount << endl;

   // for (int x = 0; x < pixelAmount; x++){
    //int x = 0;
        for (int i = 0; i < image[0].width; i++){
            for (int j = 0; j < image[0].height; j++){

                ofSetColor(pixelAverage[j * image[0].width +i]);
                ofRect(i, j, 1, 1);
                //cout<< "x = " << i << " y = " << j << "   ";
                //x++;
            //}
        }
    }
    cout << "do you see pixel averages?" << endl;
    //findPixels = false;
}
