ofxPoint
=========
This is an Openframeworks addon.

Description
-----------
a template for ofVec3f

Types:
typedef ofxPoint_<float> ofxPoint;

	typedef ofxPoint_<int> 				ofxIntPoint;
	typedef ofxPoint_<char> 			ofxCharPoint;
	typedef ofxPoint_<unsigned char> 	ofxUCharPoint;
	typedef ofxPoint_<short> 			ofxShortPoint;
	typedef ofxPoint_<unsigned short> 	ofxUShortPoint;
	typedef ofxPoint_<int> 				ofxIntPoint;
	typedef ofxPoint_<unsigned int> 	ofxUIntPoint;
	typedef ofxPoint_<long> 			ofxLongPoint;
	typedef ofxPoint_<unsigned long> 	ofxULongPoint;
	typedef ofxPoint_<float> 			ofxFloatPoint;
	typedef ofxPoint_<double> 			ofxDoublePoint;

Usage
-----
ofxPoint is float by default.

example code:

	// declare
	ofxPoint		float3d;
	ofxIntPoint		int3d;
	ofxUCharPoint	uchar3d;
	ofxDoublePoint	double3d;
		
	//scalars
	ofxIntPoint anIntpoint1(3);
	ofxIntPoint anIntpoint3(3.4445f);
	ofxIntPoint anIntpoint5('a');
	
	//ctor same type
	ofxIntPoint anIntpoint4(int3d);
	
	//ctor other types
	ofxIntPoint anIntpoint6(uchar3d);
	ofxIntPoint anIntpoint7(double3d);
	ofxIntPoint anIntpoint2(float3d);
	ofVec3f ofVec1(float3d);
	ofVec3f ofVec3(double3d);
	
	// operators work across types
	ofVec3f		ofVec_;
	double3d = double3d + ofVec_;
	
	// ofVec3f receiving ofxPoint types
	ofVec_ = float3d + ofVec_;
	ofVec_ = float3d;
	ofVec_2 = double3d;
	ofVec3f ofVec1(float3d);
	ofVec3f ofVec2(double3d);
	
	// printing like in ofVec3f
	cout << float3d << endl;
	cout << int3d << endl;
	cout << uchar3d << endl;
	cout << double3d << endl;


