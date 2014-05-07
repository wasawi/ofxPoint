#pragma once

#include "ofMain.h"
#include "ofxPoint.h"

class ofApp : public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();
	
	void process(ofxPoint p3d);
	void process(ofxIntPoint p3d);
	void process(ofxUCharPoint p3d);
	void process(ofxDoublePoint p3d);
	
	void print(ofxPoint _floatPoint,
			   ofxIntPoint _intPoint,
			   ofxUCharPoint _ucharPoint,
			   ofxDoublePoint _doublePoint){
		std::cout.precision(20);
		cout << _floatPoint << endl;
		cout << _intPoint << endl;
		cout << _ucharPoint << endl;
		cout << _doublePoint << endl;
		cout << "*********************" << endl;
	};
	
	void a();
	void b();
	
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
