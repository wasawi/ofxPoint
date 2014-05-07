#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofxPoint		float3d;
	ofxIntPoint		int3d;
	ofxUCharPoint	uchar3d;
	ofxDoublePoint	double3d;
	
	process(float3d);
	process(int3d);
	process(uchar3d);
	process(double3d);
	
	ofVec3f		ofVec_;
	ofVec3f		ofVec_2;
	ofxPoint	float3d_;

	//scalars
	ofxIntPoint anIntpoint1(3);
	ofxIntPoint anIntpoint3(3.4445f);
	ofxIntPoint anIntpoint5('a');
	
	//same type
	ofxIntPoint anIntpoint4(int3d);

	//other types
	ofxIntPoint anIntpoint6(uchar3d);
	ofxIntPoint anIntpoint7(double3d);
	ofxIntPoint anIntpoint2(float3d);

	float3d = ofVec_;
	float3d = float3d;
	float3d = float3d_;
	int3d	= float3d;
	float3d = int3d;
	uchar3d = float3d;
	float3d = uchar3d;

	float3d = float3d + ofVec_;
	
	// ofVec3f receiving my types
	ofVec_ = float3d + ofVec_;
	ofVec_ = (ofVec3f) float3d;
	ofVec_2 = (ofVec3f) double3d;
	ofVec3f ofVec1(float3d);
	ofVec3f ofVec2((ofVec3f) double3d);
	ofVec3f ofVec3(double3d);
	
}

//--------------------------------------------------------------
void ofApp::process(ofxPoint p3d)
{
	p3d += 3.141592653589793238;
	std::cout.precision(20);
	cout << p3d << endl;
	p3d.x*=2;
	cout << p3d << endl;
	cout << "note that flaot precision is not good after 6th~ digit" << endl;
}

void ofApp::process(ofxIntPoint p3d)
{
	p3d += 3.33;
	cout << p3d << endl;
	p3d.x*=2;
	cout << p3d << endl;
}

void ofApp::process(ofxUCharPoint p3d)
{
	p3d += 'a';
	cout << p3d << endl;
	p3d.x+=2;
	cout << p3d << endl;
}

void ofApp::process(ofxDoublePoint p3d)
{
	p3d.set(3.141592653589793238);
	std::cout.precision(20);
	cout << p3d << endl;
	p3d.x/=3;
	cout << p3d << endl;
	cout << "note that double precision its a lot higher than float" << endl;
	//http://stackoverflow.com/questions/5098558/float-vs-double-precision
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
