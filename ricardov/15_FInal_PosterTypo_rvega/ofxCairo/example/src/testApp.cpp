#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofSetFrameRate(100);
    
    _useCairo = false;
    _center = ofPoint(ofGetWidth()/2.0f, ofGetHeight()/2.0f);
    _addNewPath();
    _paths[_paths.size()-1].moveTo(_calculateNextPoint());
    
    _cairo.setLineCap(CAIRO_LINE_CAP_ROUND);
}

ofPoint testApp::_calculateNextPoint()
{
    float s = ofGetHeight()/2;
    float t = ofGetElapsedTimef();
    ofPoint p = _center;
    p += ofPoint(cos(t)*(sin(t*(cos(t)/PI))*s), sin(t)*(cos(t*(sin(t)/PI))*s));
    
    return p;
}

void testApp::_addNewPath()
{
    ofPath p;
    p.setFilled(false);
    p.setStrokeWidth(ofRandom(10.0f, 30.0f));
    
    ofColor c;
    
    if (ofRandom(1.0f) > .85f)	
    {
        c = ofFloatColor(1.0, .2f, ofRandom(.3f, .6f));
    }
    else
    {
        c = ofFloatColor(.3, ofRandom(.9f, 1.0f), ofRandom(.7f, 1.0f));
    }
    
    p.setColor(c);
    
    _paths.push_back(p);
}

//--------------------------------------------------------------
void testApp::update()
{
    float t = ofGetElapsedTimef();
    
    ofPoint p = _calculateNextPoint();
    
    if (ofRandom(1.0f) > .96f)
    {
        _paths[_paths.size()-1].simplify();
        _addNewPath();
        _paths[_paths.size()-1].moveTo(p);
    }
    else
    {
        _paths[_paths.size()-1].curveTo(p);
    }
    
    if (_paths.size() > 20) _paths.erase(_paths.begin());
    
    int numCommands = 0;
    
    for (int i = 0, s = _paths.size(); i < s; i++)
    {
        int num = _paths[i].getSubPaths().size();
        
        for (int j = 0; j < num; j++)
        {
            numCommands += _paths[i].getSubPaths()[j].getCommands().size();
        }
    }
    
    cout << "num commands: " << numCommands << endl;
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofBackground(20);
    
    if (_useCairo) _cairo.begin();
    
    for (vector<ofPath>::iterator p = _paths.begin(); p != _paths.end(); p++)
    {
        p->draw();
    }
    
    if (_useCairo)
    {
        _cairo.end();
        _cairo.draw();
    }
    
    stringstream s;
    s << "FPS: " << (int)ofGetFrameRate();
    s << " | current renderer: ";
    s << (_useCairo ? "CAIRO" : "OPENGL");
    s << " | hit RETURN to toogle renderer";
    
    ofDrawBitmapString(s.str(), 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    if (key == OF_KEY_RETURN) _useCairo = !_useCairo;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

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