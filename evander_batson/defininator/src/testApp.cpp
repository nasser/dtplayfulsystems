#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(94, 170, 255);
    
    sansSerif.loadFont("Oxygen.otf", 50, true, true);
	sansSerif.setLineHeight(18.0f);
	sansSerif.setLetterSpacing(1.037);
    
	serif.loadFont("times.ttf", 20, false);
	serif.setLineHeight(30.0f);
	serif.setLetterSpacing(1.037);
    
    crawlerType.loadFont("Oxygen.otf", 670, false);
	crawlerType.setLineHeight(30.0f);
	crawlerType.setLetterSpacing(1.037);
    
    randomWord = ofRandom(0,34);
    maxCrawl = 100;
    crawlPosition = maxCrawl;
    maxTimer = 1000;
    timer = maxTimer;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    crawlPosition--;
    timer--;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    definitions();

}

void testApp::definitions() {
    
    if (timer > 0) {
    
    ofSetColor(255,255,255);
    
    wordBank();
    
    sansSerif.drawString(definitionH[randomWord], ofGetWidth()/8, ofGetHeight()/3);
    
    serif.drawString(definitionP[randomWord], ofGetWidth()/8, ofGetHeight()/2.3);
    
    crawler();
    
    } else {
        reset();
    }
    
}

void testApp::crawler() {
    
    ofSetColor(255, 255, 255, 50);
    
    crawlerType.drawString(definitionH[randomWord], crawlPosition, ofGetHeight()/1.1);
    
}

void testApp::reset() {
    timer = maxTimer;
    randomWord = ofRandom(0,34);
    crawlPosition = maxCrawl;
}

void testApp::wordBank() {
    
    definitionH.push_back("Deliverable");
    definitionH.push_back("Usability Testing");
    definitionH.push_back("Ask");
    definitionH.push_back("Client");
    definitionH.push_back("Holistic Approach");
    definitionH.push_back("Leverage");
    definitionH.push_back("Paradigm Shift");
    definitionH.push_back("Ping");
    definitionH.push_back("Synergy");
    definitionH.push_back("Milestone");
    definitionH.push_back("Next Steps");
    definitionH.push_back("Metrics");
    definitionH.push_back("Analytics");
    definitionH.push_back("Eyeball");
    definitionH.push_back("Best Practice");
    definitionH.push_back("Disruptive");
    definitionH.push_back("Immersion");
    definitionH.push_back("Mission Critical");
    definitionH.push_back("Seamless");
    definitionH.push_back("Value-add");
    definitionH.push_back("Responsive");
    definitionH.push_back("Scalability");
    definitionH.push_back("Skeuomorphic");
    definitionH.push_back("Look And Feel");
    definitionH.push_back("Workflow");
    definitionH.push_back("Life-Cycle");
    definitionH.push_back("User-Centric");
    definitionH.push_back("Facilitate");
    definitionH.push_back("Viral");
    definitionH.push_back("Pipeline");
    definitionH.push_back("Anguilla Bank Skink Lizard");
    definitionH.push_back("Poop Sock");
    definitionH.push_back("Sandwich Tern");
    definitionH.push_back("Crystal Healing");
    definitionH.push_back("Woo");
    
    definitionP.push_back("Noun. A product of a development process.");
    definitionP.push_back("Verb. Usability testing is a technique used in  user-centered  \n interaction design to evaluate a product by testing it on users.");
    definitionP.push_back("Noun. The baseline investment of a client as demanded by \n the provider in order to begin providing service.");
    definitionP.push_back("Noun. A desktop computer or workstation that is capable of \n obtaining  information and applications from a server.");
    definitionP.push_back("Noun. A process aiming to affect the entirety system.");
    definitionP.push_back("Verb. To use a resource to maximum advantage.");
    definitionP.push_back("Noun. a radical change in underlying technology in a network.");
    definitionP.push_back("Verb. To check the availability of a client or colleague.");
    definitionP.push_back("Noun. The interaction of elements that when combined produce \n a total effect that is greater than the sum of the individual elements, and contributions in a product.");
    definitionP.push_back("Noun. A major success-point in the timeline of a development \n cycle.");
    definitionP.push_back("Noun. The follow-up tasks after a meeting.");
    definitionP.push_back("Noun. The quantified measures of value and change in an asset.");
    definitionP.push_back("Noun. A system for measuring the successes and failures of a \n product. The first known example of such a system was created by created by Google Inc.");
    definitionP.push_back("Noun. A unique view by a user on an online product. A hit.");
    definitionP.push_back("Noun. The universally acceptable method of developing software.");
    definitionP.push_back("Adv. A disruption in the market that can be capitalized on for \n commercial gain.");
    definitionP.push_back("Noun. The total engagement of a user in a product.");
    definitionP.push_back("Noun. The requirements needed in order for a project to stay solvent.");
    definitionP.push_back("Adj. Two interfaces that are smoothly combined into a unified product.");
    definitionP.push_back("Noun. An economically beneificial side-effect of a process.");
    definitionP.push_back("Adj. Software that scales and adapts to the device it is used on.");
    definitionP.push_back("Adj. A process that can be successful on both large and small \n implementations.");
    definitionP.push_back("Adj. Digital interface features that are symbolic of preexisting \n and historical interfaces.");
    definitionP.push_back("Noun. The apperance of an the interface created for targeted \n consumer markets.");
    definitionP.push_back("Noun. A demonstratable process that achieves results in a \n itemizied and consistant manner.");
    definitionP.push_back("Noun. The totality of the exchange, use, and discard of \n a product by a user.");
    definitionP.push_back("Adj. The limited perspective consumers in which they \n assume an overinflation of their personal importance within product.");
    definitionP.push_back("Verb. The capacity for a CEO or shareholder to produce \n results from the labors of a team of workers.");
    definitionP.push_back("Adj. Content that users distribute exponentially without \n the need to compensate them.");
    definitionP.push_back("Noun. An organized system of workflows that systematically \n feed into a net gain of productivity.");
    definitionH.push_back("Noun. A species of reptiles native to the Carribbean island of Anguilla");
    definitionH.push_back("Noun. [Slang] A portable human waste receptacle for employees \n to use without having to leave their work station.");
    definitionH.push_back("Noun. A crested sea bird. Not to be confused with the Chinese \n Crested Tern or the Elegant Tern.");
    definitionH.push_back("Noun. The practice of correcting all ailments by use of quartz. \n Traditionally less expensive than providing employee health plans.");
    definitionH.push_back("Interjection. An expression of pure, unadulterated bliss and contentment.");
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r' ){
        randomWord = ofRandom(0,34);
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
