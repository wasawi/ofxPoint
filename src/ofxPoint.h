#pragma once

#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"
#include "ofConstants.h"
#include "ofUtils.h"

#include <cmath>
#include <iostream>

template < typename T >
class ofxPoint_ {
public:
	T x,y,z;
    
    static const int DIM = 3;
	
	ofxPoint_();
	ofxPoint_( T _x, T _y, T _z=0 );
	/// assigns scalar to x, y, and z
	explicit ofxPoint_( T _scalar );
	
    ofxPoint_( const ofVec2f& vec );
    ofxPoint_( const ofVec3f& vec );
    ofxPoint_( const ofVec4f& vec );
	
	//j Multytype constructor
	template<typename S>
    ofxPoint_( const ofxPoint_<S>& vec );
	//j T casting for ofV3c3f
	operator ofVec3f () const;

	T * getPtr() {
		return (T*)&x;
	}
	const T * getPtr() const {
		return (const T *)&x;
	}
	
	T& operator[]( int n ){
		return getPtr()[n];
	}
	
	T operator[]( int n ) const {
		return getPtr()[n];
	}
	
    
	// Getters and Setters.
    //
    void set( T _x, T _y, T _z = 0 );
    void set( const ofxPoint_& vec );
	void set( T _scalar );
	
    // Check similarity/equality.
    //
    bool operator==( const ofxPoint_& vec ) const;
    bool operator!=( const ofxPoint_& vec ) const;
    bool match( const ofxPoint_& vec, T tolerance=0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 */
    bool isAligned( const ofxPoint_& vec, T tolerance=0.0001 ) const;
    bool align( const ofxPoint_& vec, T tolerance=0.0001 ) const;
    bool isAlignedRad( const ofxPoint_& vec, T tolerance=0.0001 ) const;
    bool alignRad( const ofxPoint_& vec, T tolerance=0.0001 ) const;
	
    // Operator overloading for ofxPoint_
    //
    ofxPoint_  operator+( const ofxPoint_& pnt ) const;
    ofxPoint_& operator+=( const ofxPoint_& pnt );
    ofxPoint_  operator-( const ofxPoint_& vec ) const;
    ofxPoint_& operator-=( const ofxPoint_& vec );
    ofxPoint_  operator*( const ofxPoint_& vec ) const;
    ofxPoint_& operator*=( const ofxPoint_& vec );
    ofxPoint_  operator/( const ofxPoint_& vec ) const;
    ofxPoint_& operator/=( const ofxPoint_& vec );
    ofxPoint_  operator-() const;
	
    //operator overloading for T
    //
//    ofxPoint_  operator=( const T f ) const;
    ofxPoint_  operator+( const T f ) const;
    ofxPoint_& operator+=( const T f );
 	ofxPoint_  operator-( const T f ) const;
    ofxPoint_& operator-=( const T f );
    ofxPoint_  operator*( const T f ) const;
    ofxPoint_& operator*=( const T f );
    ofxPoint_  operator/( const T f ) const;
    ofxPoint_& operator/=( const T f );
	
	
	// Operator overloading for ofxPoint_
	//
	//
//	template < typename S >	friend ostream& operator<<(ostream& os, const ofxPoint_<T> vec);
//	template < typename S >	friend istream& operator>>(istream& is, ofxPoint_<S>& vec);
	
	friend std::ostream& operator<<( std::ostream& lhs, const ofxPoint_<T>& rhs )
	{
		lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
		return lhs;
	}

	
    //Scale
    //
    ofxPoint_  getScaled( const T length ) const;
    ofxPoint_& scale( const T length );
    
	
    // Rotation
    //
    ofxPoint_  getRotated( T angle, const ofxPoint_& axis ) const;
    ofxPoint_  getRotatedRad( T angle, const ofxPoint_& axis ) const;
    ofxPoint_& rotate( T angle, const ofxPoint_& axis );
    ofxPoint_& rotateRad( T angle, const ofxPoint_& axis );
    ofxPoint_  getRotated(T ax, T ay, T az) const;
    ofxPoint_  getRotatedRad(T ax, T ay, T az) const;
    ofxPoint_& rotate(T ax, T ay, T az);
    ofxPoint_& rotateRad(T ax, T ay, T az);
    
    
    // Rotation - point around pivot
    //    
    ofxPoint_   getRotated( T angle, const ofxPoint_& pivot, const ofxPoint_& axis ) const;
    ofxPoint_&  rotate( T angle, const ofxPoint_& pivot, const ofxPoint_& axis );
    ofxPoint_   getRotatedRad( T angle, const ofxPoint_& pivot, const ofxPoint_& axis ) const;
    ofxPoint_&  rotateRad( T angle, const ofxPoint_& pivot, const ofxPoint_& axis );    
	
	
    // Map point to coordinate system defined by origin, vx, vy, and vz.
    //
    ofxPoint_ getMapped( const ofxPoint_& origin,
					  const ofxPoint_& vx,
					  const ofxPoint_& vy,
					  const ofxPoint_& vz ) const;
    ofxPoint_& map( const ofxPoint_& origin,
				 const ofxPoint_& vx,
				 const ofxPoint_& vy,
				 const ofxPoint_& vz );
	
	
    // Distance between two points.
    //
    T distance( const ofxPoint_& pnt) const;
    T squareDistance( const ofxPoint_& pnt ) const;
	
	
    // Linear interpolation.
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofxPoint_   getInterpolated( const ofxPoint_& pnt, T p ) const;
    ofxPoint_&  interpolate( const ofxPoint_& pnt, T p );
    ofxPoint_   getMiddle( const ofxPoint_& pnt ) const;
    ofxPoint_&  middle( const ofxPoint_& pnt );
    ofxPoint_&  average( const ofxPoint_* points, int num );
    
	
    // Normalization
    //
    ofxPoint_  getNormalized() const;
    ofxPoint_& normalize();
	
	
    // Limit length.
    //
    ofxPoint_  getLimited(T max) const;
    ofxPoint_& limit(T max);
	
	
    // Perpendicular vector.
    //
    ofxPoint_  getCrossed( const ofxPoint_& vec ) const;
    ofxPoint_& cross( const ofxPoint_& vec );
    /**
	 * Normalized perpendicular.
	 */
    ofxPoint_  getPerpendicular( const ofxPoint_& vec ) const;
    ofxPoint_& perpendicular( const ofxPoint_& vec );
	
	
    // Length
    //
    T length() const;
    T lengthSquared() const;

    /**
	 * Angle (deg) between two vectors.
	 * This is an unsigned relative angle from 0 to 180.
	 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
	 */
    T angle( const ofxPoint_& vec ) const;
    T angleRad( const ofxPoint_& vec ) const;
	
	
    // Dot Product
    //
    T dot( const ofxPoint_& vec ) const;
	
	
	
    //-----------------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofxPoint_ rescaled( const T length ) const;
	
    // scale
    ofxPoint_& rescale( const T length );
	
    // getRotated
    ofxPoint_ rotated( T angle, const ofxPoint_& axis ) const;
	
    // getRotated should this be const???
    ofxPoint_ rotated(T ax, T ay, T az);
	
    // getNormalized
    ofxPoint_ normalized() const;
	
    // getLimited
    ofxPoint_ limited(T max) const;
	
    // getCrossed
    ofxPoint_ crossed( const ofxPoint_& vec ) const;
	
    // getPerpendicular
    ofxPoint_ perpendiculared( const ofxPoint_& vec ) const;
    
    // use getMapped
    ofxPoint_  mapped( const ofxPoint_& origin,
					const ofxPoint_& vx,
					const ofxPoint_& vy,
					const ofxPoint_& vz ) const;
	
    // use squareDistance
    T  distanceSquared( const ofxPoint_& pnt ) const;
	
    // use getInterpolated
    ofxPoint_ 	interpolated( const ofxPoint_& pnt, T p ) const;
	
    // use getMiddle
    ofxPoint_ 	middled( const ofxPoint_& pnt ) const;
    
    // use getRotated
    ofxPoint_ 	rotated( T angle,
						const ofxPoint_& pivot,
						const ofxPoint_& axis ) const;    

    // return all zero vector
    static ofxPoint_ zero() { return ofxPoint_(0, 0, 0); }
    
    // return all one vector
    static ofxPoint_ one() { return ofxPoint_(1, 1, 1); }
};

template class ofxPoint_<char>;
template class ofxPoint_<unsigned char>;
template class ofxPoint_<short>;
template class ofxPoint_<unsigned short>;
template class ofxPoint_<int>;
template class ofxPoint_<unsigned int>;
template class ofxPoint_<long>;
template class ofxPoint_<unsigned long>;
template class ofxPoint_<float>;
template class ofxPoint_<double>;

typedef ofxPoint_<float> ofxPoint;

typedef ofxPoint_<int> ofxIntPoint;
typedef ofxPoint_<char> ofxCharPoint;
typedef ofxPoint_<unsigned char> ofxUCharPoint;
typedef ofxPoint_<short> ofxShortPoint;
typedef ofxPoint_<unsigned short> ofxUShortPoint;
typedef ofxPoint_<int> ofxIntPoint;
typedef ofxPoint_<unsigned int> ofxUIntPoint;
typedef ofxPoint_<long> ofxLongPoint;
typedef ofxPoint_<unsigned long> ofxULongPoint;
typedef ofxPoint_<float> ofxFloatPoint;
typedef ofxPoint_<double> ofxDoublePoint;

typedef ofxPoint& ofxPointRef;
typedef ofxCharPoint& ofxCharPointRef;
typedef ofxUCharPoint& ofxUCharPointRef;
typedef ofxShortPoint& ofxShortPointRef;
typedef ofxUShortPoint& ofxUShortPointRef;
typedef ofxIntPoint& ofxIntPointRef;
typedef ofxUIntPoint& ofxUIntPointRef;
typedef ofxLongPoint& ofxLongPointRef;
typedef ofxULongPoint& ofxULongPointRef;
typedef ofxFloatPoint& ofFloatPointRef;
typedef ofxDoublePoint& ofxDoublePointRef;

// Non-Member operators
//
//
template < typename T >
ofxPoint_<T> operator+( T f, const ofxPoint_<T>& vec );
template < typename T >
ofxPoint_<T> operator-( T f, const ofxPoint_<T>& vec );
template < typename T >
ofxPoint_<T> operator*( T f, const ofxPoint_<T>& vec );
template < typename T >
ofxPoint_<T> operator/( T f, const ofxPoint_<T>& vec );


/////////////////
// Implementation
/////////////////

template < typename T >
inline ofxPoint_<T>::ofxPoint_( const ofVec2f& vec ):x(vec.x), y(vec.y), z(0) {}
template < typename T >
inline ofxPoint_<T>::ofxPoint_( const ofVec3f& vec ):x(vec.x), y(vec.y), z(vec.z) {}
template < typename T >
inline ofxPoint_<T>::ofxPoint_( const ofVec4f& vec ):x(vec.x), y(vec.y), z(vec.z) {}
template < typename T >
inline ofxPoint_<T>::ofxPoint_(): x(0), y(0), z(0) {};
template < typename T >
inline ofxPoint_<T>::ofxPoint_( T _all ): x(_all), y(_all), z(_all) {};
template < typename T >
inline ofxPoint_<T>::ofxPoint_( T _x, T _y, T _z ):x(_x), y(_y), z(_z) {}

// Constructor from other types
//
//j
template < typename T >
template < typename S >
inline ofxPoint_<T>::ofxPoint_( const ofxPoint_<S>& vec ):x(vec.x), y(vec.y), z(vec.z) {}

// Type casting for ofV3c3f
//
//j
template < typename T >
inline ofxPoint_<T>::operator ofVec3f() const
{
    ofVec3f output;
    output = ofVec3f(x,y,z);
    return output;
}

// Getters and Setters.
//
//
template < typename T >
inline void ofxPoint_<T>::set( T _scalar ) {
	x = _scalar;
	y = _scalar;
	z = _scalar;
}
template < typename T >
inline void ofxPoint_<T>::set( T _x, T _y, T _z ) {
	x = _x;
	y = _y;
	z = _z;
}
template < typename T >
inline void ofxPoint_<T>::set( const ofxPoint_& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}


// Check similarity/equality.
//
//
template < typename T >
inline bool ofxPoint_<T>::operator==( const ofxPoint_& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z);
}
template < typename T >
inline bool ofxPoint_<T>::operator!=( const ofxPoint_& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z);
}
template < typename T >
inline bool ofxPoint_<T>::match( const ofxPoint_& vec, T tolerance ) const{
	return (fabs(x - vec.x) < tolerance)
	&& (fabs(y - vec.y) < tolerance)
	&& (fabs(z - vec.z) < tolerance);
}

/**
 * Checks if vectors look in the same direction.
 */
template < typename T >
inline bool ofxPoint_<T>::isAligned( const ofxPoint_& vec, T tolerance ) const {
	T angle = this->angle( vec );
	return  angle < tolerance;
}
template < typename T >
inline bool ofxPoint_<T>::align( const ofxPoint_& vec, T tolerance ) const {
    return isAligned( vec, tolerance );
}
template < typename T >
inline bool ofxPoint_<T>::isAlignedRad( const ofxPoint_& vec, T tolerance ) const {
	T angle = this->angleRad( vec );
	return  angle < tolerance;
}
template < typename T >
inline bool ofxPoint_<T>::alignRad( const ofxPoint_& vec, T tolerance ) const {
    return isAlignedRad( vec, tolerance );
}


// Operator overloading for ofxPoint_
//
//
/*template < typename S >
ostream& operator<<( ostream& os, const ofxPoint_<T>& vec ) {
//	os << "[" << ofToString(vec.x) << "," << ofToString(vec.y) << "," << ofToString(vec.z) << "]";
	os << "[" << vec.x << "," << vec.y << "," << vec.z << "]";

	return os;
}
template < typename S >
inline istream& operator>>( istream& is, ofxPoint_<S>& vec ) {
	is >> vec.x;
	is.ignore(2);
	is >> vec.y;
	is.ignore(2);
	is >> vec.z;
	return is;
}*/


// Operator overloading for ofxPoint_
//

template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator+( const ofxPoint_& pnt ) const {
	return ofxPoint_( x+pnt.x, y+pnt.y, z+pnt.z );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator+=( const ofxPoint_& pnt ) {
	x+=pnt.x;
	y+=pnt.y;
	z+=pnt.z;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator-( const ofxPoint_& vec ) const {
	return ofxPoint_( x-vec.x, y-vec.y, z-vec.z );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator-=( const ofxPoint_& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator*( const ofxPoint_& vec ) const {
	return ofxPoint_( x*vec.x, y*vec.y, z*vec.z );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator*=( const ofxPoint_& vec ) {
	x*=vec.x;
	y*=vec.y;
	z*=vec.z;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator/( const ofxPoint_& vec ) const {
	return ofxPoint_( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator/=( const ofxPoint_& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator-() const {
	return ofxPoint_( -x, -y, -z );
}


//operator overloading for T
//
//
/*
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator=( const T f) const {
	x = f;
	y = f;
	z = f;
	return *this;
}*/
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator+( const T f ) const {
	return ofxPoint_( x+f, y+f, z+f);
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator+=( const T f ) {
	x += f;
	y += f;
	z += f;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator-( const T f ) const {
	return ofxPoint_( x-f, y-f, z-f);
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator-=( const T f ) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator*( const T f ) const {
	return ofxPoint_( x*f, y*f, z*f );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator*=( const T f ) {
	x*=f;
	y*=f;
	z*=f;
	return *this;
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::operator/( const T f ) const {
	if(f == 0) return ofxPoint_( x, y, z);
	
	return ofxPoint_( x/f, y/f, z/f );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::operator/=( const T f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	z/=f;
	return *this;
}


//Scale
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::rescaled( const T length ) const {
	return getScaled(length);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getScaled( const T length ) const {
	T l = (T)sqrt(x*x + y*y + z*z);
	if( l > 0 )
		return ofxPoint_( (x/l)*length, (y/l)*length, (z/l)*length );
	else
		return ofxPoint_();
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rescale( const T length ) {
	return scale(length);
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::scale( const T length ) {
	T l = (T)sqrt(x*x + y*y + z*z);
	if (l > 0) {
		x = (x/l)*length;
		y = (y/l)*length;
		z = (z/l)*length;
	}
	return *this;
}



// Rotation
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::rotated( T angle, const ofxPoint_& axis ) const {
	return getRotated(angle, axis);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotated( T angle, const ofxPoint_& axis ) const {
	ofxPoint_ ax = axis.normalized();
	T a = (T)(angle*DEG_TO_RAD);
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	return ofxPoint_( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotatedRad( T angle, const ofxPoint_& axis ) const {
	ofxPoint_ ax = axis.normalized();
	T a = angle;
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	return ofxPoint_( x*(ax.x*ax.x*cosb + cosa)
				   + y*(ax.x*ax.y*cosb - ax.z*sina)
				   + z*(ax.x*ax.z*cosb + ax.y*sina),
				   x*(ax.y*ax.x*cosb + ax.z*sina)
				   + y*(ax.y*ax.y*cosb + cosa)
				   + z*(ax.y*ax.z*cosb - ax.x*sina),
				   x*(ax.z*ax.x*cosb - ax.y*sina)
				   + y*(ax.z*ax.y*cosb + ax.x*sina)
				   + z*(ax.z*ax.z*cosb + cosa) );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotate( T angle, const ofxPoint_& axis ) {
	ofxPoint_ ax = axis.normalized();
	T a = (T)(angle*DEG_TO_RAD);
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	T ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	T nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}

template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotateRad(T angle, const ofxPoint_& axis ) {
	ofxPoint_ ax = axis.normalized();
	T a = angle;
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T nx = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	T ny = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	T nz = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	x = nx; y = ny; z = nz;
	return *this;
}

// const???
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::rotated(T ax, T ay, T az) {
	return getRotated(ax,ay,az);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotated(T ax, T ay, T az) const {
	T a = (T)cos(DEG_TO_RAD*(ax));
	T b = (T)sin(DEG_TO_RAD*(ax));
	T c = (T)cos(DEG_TO_RAD*(ay));
	T d = (T)sin(DEG_TO_RAD*(ay));
	T e = (T)cos(DEG_TO_RAD*(az));
	T f = (T)sin(DEG_TO_RAD*(az));
	
	T nx = c * e * x - c * f * y + d * z;
	T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofxPoint_( nx, ny, nz );
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotatedRad(T ax, T ay, T az) const {
	T a = cos(ax);
	T b = sin(ax);
	T c = cos(ay);
	T d = sin(ay);
	T e = cos(az);
	T f = sin(az);
	
	T nx = c * e * x - c * f * y + d * z;
	T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	return ofxPoint_( nx, ny, nz );
}

template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotate(T ax, T ay, T az) {
	T a = (T)cos(DEG_TO_RAD*(ax));
	T b = (T)sin(DEG_TO_RAD*(ax));
	T c = (T)cos(DEG_TO_RAD*(ay));
	T d = (T)sin(DEG_TO_RAD*(ay));
	T e = (T)cos(DEG_TO_RAD*(az));
	T f = (T)sin(DEG_TO_RAD*(az));
	
	T nx = c * e * x - c * f * y + d * z;
	T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}

template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotateRad(T ax, T ay, T az) {
	T a = cos(ax);
	T b = sin(ax);
	T c = cos(ay);
	T d = sin(ay);
	T e = cos(az);
	T f = sin(az);
	
	T nx = c * e * x - c * f * y + d * z;
	T ny = (a * f + b * d * e) * x + (a * e - b * d * f) * y - b * c * z;
	T nz = (b * f - a * d * e) * x + (a * d * f + b * e) * y + a * c * z;
	
	x = nx; y = ny; z = nz;
	return *this;
}


// Rotate point by angle (deg) around line defined by pivot and axis.
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::rotated( T angle,
								const ofxPoint_& pivot,
								const ofxPoint_& axis ) const{
	return getRotated(angle, pivot, axis);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotated( T angle,
								   const ofxPoint_& pivot,
								   const ofxPoint_& axis ) const
{
	ofxPoint_ ax = axis.normalized();
	T tx = x - pivot.x;
	T ty = y - pivot.y;
	T tz = z - pivot.z;
	
	T a = (T)(angle*DEG_TO_RAD);
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	T yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	T zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofxPoint_( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}

template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getRotatedRad( T angle,
									  const ofxPoint_& pivot,
									  const ofxPoint_& axis ) const
{
	ofxPoint_ ax = axis.normalized();
	T tx = x - pivot.x;
	T ty = y - pivot.y;
	T tz = z - pivot.z;
	
	T a = angle;
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T xrot = tx*(ax.x*ax.x*cosb + cosa)
	+ ty*(ax.x*ax.y*cosb - ax.z*sina)
	+ tz*(ax.x*ax.z*cosb + ax.y*sina);
	T yrot = tx*(ax.y*ax.x*cosb + ax.z*sina)
	+ ty*(ax.y*ax.y*cosb + cosa)
	+ tz*(ax.y*ax.z*cosb - ax.x*sina);
	T zrot = tx*(ax.z*ax.x*cosb - ax.y*sina)
	+ ty*(ax.z*ax.y*cosb + ax.x*sina)
	+ tz*(ax.z*ax.z*cosb + cosa);
	
	
	return ofxPoint_( xrot+pivot.x, yrot+pivot.y, zrot+pivot.z );
}

template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotate( T angle,
								const ofxPoint_& pivot,
								const ofxPoint_& axis )
{
	ofxPoint_ ax = axis.normalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	T a = (T)(angle*DEG_TO_RAD);
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	T yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	T zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}

template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::rotateRad( T angle,
								   const ofxPoint_& pivot,
								   const ofxPoint_& axis )
{
	ofxPoint_ ax = axis.normalized();
	x -= pivot.x;
	y -= pivot.y;
	z -= pivot.z;
	
	T a = angle;
	T sina = sin( a );
	T cosa = cos( a );
	T cosb = 1.0f - cosa;
	
	T xrot = x*(ax.x*ax.x*cosb + cosa)
	+ y*(ax.x*ax.y*cosb - ax.z*sina)
	+ z*(ax.x*ax.z*cosb + ax.y*sina);
	T yrot = x*(ax.y*ax.x*cosb + ax.z*sina)
	+ y*(ax.y*ax.y*cosb + cosa)
	+ z*(ax.y*ax.z*cosb - ax.x*sina);
	T zrot = x*(ax.z*ax.x*cosb - ax.y*sina)
	+ y*(ax.z*ax.y*cosb + ax.x*sina)
	+ z*(ax.z*ax.z*cosb + cosa);
	
	x = xrot + pivot.x;
	y = yrot + pivot.y;
	z = zrot + pivot.z;
	
	return *this;
}




// Map point to coordinate system defined by origin, vx, vy, and vz.
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::mapped( const ofxPoint_& origin,
							   const ofxPoint_& vx,
							   const ofxPoint_& vy,
							   const ofxPoint_& vz ) const{
	return getMapped(origin, vx, vy, vz);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getMapped( const ofxPoint_& origin,
								  const ofxPoint_& vx,
								  const ofxPoint_& vy,
								  const ofxPoint_& vz ) const
{
	return ofxPoint_( origin.x + x*vx.x + y*vy.x + z*vz.x,
				   origin.y + x*vx.y + y*vy.y + z*vz.y,
				   origin.z + x*vx.z + y*vy.z + z*vz.z );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::map( const ofxPoint_& origin,
							 const ofxPoint_& vx,
							 const ofxPoint_& vy,
							 const ofxPoint_& vz )
{
	T xmap = origin.x + x*vx.x + y*vy.x + z*vz.x;
	T ymap =  origin.y + x*vx.y + y*vy.y + z*vz.y;
	z = origin.z + x*vx.z + y*vy.z + z*vz.z;
	x = xmap;
	y = ymap;
	return *this;
}


// Distance between two points.
//
//
template < typename T >
inline T ofxPoint_<T>::distance( const ofxPoint_& pnt) const {
	T vx = x-pnt.x;
	T vy = y-pnt.y;
	T vz = z-pnt.z;
	return (T)sqrt(vx*vx + vy*vy + vz*vz);
}
template < typename T >
inline T  ofxPoint_<T>::distanceSquared( const ofxPoint_& pnt ) const{
	return squareDistance(pnt);
}
template < typename T >
inline T  ofxPoint_<T>::squareDistance( const ofxPoint_& pnt ) const {
	T vx = x-pnt.x;
	T vy = y-pnt.y;
	T vz = z-pnt.z;
	return vx*vx + vy*vy + vz*vz;
}



// Linear interpolation.
//
//
/**
 * p==0.0 results in this point, p==0.5 results in the
 * midpoint, and p==1.0 results in pnt being returned.
 */
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::interpolated( const ofxPoint_& pnt, T p ) const {
	return getInterpolated(pnt,p);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getInterpolated( const ofxPoint_& pnt, T p ) const {
	return ofxPoint_( x*(1-p) + pnt.x*p,
				   y*(1-p) + pnt.y*p,
				   z*(1-p) + pnt.z*p );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::interpolate( const ofxPoint_& pnt, T p ) {
	x = x*(1-p) + pnt.x*p;
	y = y*(1-p) + pnt.y*p;
	z = z*(1-p) + pnt.z*p;
	return *this;
}

template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::middled( const ofxPoint_& pnt ) const {
	return getMiddle(pnt);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getMiddle( const ofxPoint_& pnt ) const {
	return ofxPoint_( (x+pnt.x)/2.0f, (y+pnt.y)/2.0f, (z+pnt.z)/2.0f );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::middle( const ofxPoint_& pnt ) {
	x = (x+pnt.x)/2.0f;
	y = (y+pnt.y)/2.0f;
	z = (z+pnt.z)/2.0f;
	return *this;
}


// Average (centroid) among points.
// Addition is sometimes useful for calculating averages too.
//
//
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::average( const ofxPoint_* points, int num ) {
	x = 0.f;
	y = 0.f;
	z = 0.f;
	for( int i=0; i<num; i++) {
		x += points[i].x;
		y += points[i].y;
		z += points[i].z;
	}
	x /= num;
	y /= num;
	z /= num;
	return *this;
}



// Normalization
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::normalized() const {
	return getNormalized();
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getNormalized() const {
	T length = (T)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		return ofxPoint_( x/length, y/length, z/length );
	} else {
		return ofxPoint_();
	}
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::normalize() {
	T length = (T)sqrt(x*x + y*y + z*z);
	if( length > 0 ) {
		x /= length;
		y /= length;
		z /= length;
	}
	return *this;
}



// Limit length.
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::limited(T max) const {
	return getLimited(max);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getLimited(T max) const {
    ofxPoint_ limited;
    T lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        limited.set( x*ratio, y*ratio, z*ratio);
    } else {
        limited.set(x,y,z);
    }
    return limited;
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::limit(T max) {
    T lengthSquared = (x*x + y*y + z*z);
    if( lengthSquared > max*max && lengthSquared > 0 ) {
        T ratio = max/(T)sqrt(lengthSquared);
        x *= ratio;
        y *= ratio;
        z *= ratio;
    }
    return *this;
}


// Perpendicular vector.
//
//
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::crossed( const ofxPoint_& vec ) const {
	return getCrossed(vec);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getCrossed( const ofxPoint_& vec ) const {
	return ofxPoint_( y*vec.z - z*vec.y,
				   z*vec.x - x*vec.z,
				   x*vec.y - y*vec.x );
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::cross( const ofxPoint_& vec ) {
	T _x = y*vec.z - z*vec.y;
	T _y = z*vec.x - x*vec.z;
	z = x*vec.y - y*vec.x;
	x = _x;
	y = _y;
	return *this;
}

/**
 * Normalized perpendicular.
 */
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::perpendiculared( const ofxPoint_& vec ) const {
	return getPerpendicular(vec);
}
template < typename T >
inline ofxPoint_<T> ofxPoint_<T>::getPerpendicular( const ofxPoint_& vec ) const {
	T crossX = y*vec.z - z*vec.y;
	T crossY = z*vec.x - x*vec.z;
	T crossZ = x*vec.y - y*vec.x;
	
	T length = (T)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 )
		return ofxPoint_( crossX/length, crossY/length, crossZ/length );
	else
		return ofxPoint_();
}
template < typename T >
inline ofxPoint_<T>& ofxPoint_<T>::perpendicular( const ofxPoint_& vec ) {
	T crossX = y*vec.z - z*vec.y;
	T crossY = z*vec.x - x*vec.z;
	T crossZ = x*vec.y - y*vec.x;
	
	T length = (T)sqrt(crossX*crossX +
							   crossY*crossY +
							   crossZ*crossZ);
	
	if( length > 0 ) {
		x = crossX/length;
		y = crossY/length;
		z = crossZ/length;
	} else {
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}
	
	return *this;
}


// Length
//
//
template < typename T >
inline T ofxPoint_<T>::length() const {
	return (T)sqrt( x*x + y*y + z*z );
}
template < typename T >
inline T ofxPoint_<T>::lengthSquared() const {
	return (T)(x*x + y*y + z*z);
}



/**
 * Angle (deg) between two vectors.
 * This is an unsigned relative angle from 0 to 180.
 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
 */
template < typename T >
inline T ofxPoint_<T>::angle( const ofxPoint_& vec ) const {
	ofxPoint_ n1 = this->normalized();
	ofxPoint_ n2 = vec.normalized();
	return (T)(acos( n1.dot(n2) )*RAD_TO_DEG);
}
template < typename T >
inline T ofxPoint_<T>::angleRad( const ofxPoint_& vec ) const {
	ofxPoint_ n1 = this->normalized();
	ofxPoint_ n2 = vec.normalized();
	return (T)acos( n1.dot(n2) );
}



/**
 * Dot Product.
 */
template < typename T >
inline T ofxPoint_<T>::dot( const ofxPoint_& vec ) const {
	return x*vec.x + y*vec.y + z*vec.z;
}





// Non-Member operators
//
//
template < typename T >
inline ofxPoint_<T> operator+( T f, const ofxPoint_<T>& vec ) {
    return ofxPoint_<T>( f+vec.x, f+vec.y, f+vec.z );
}
template < typename T >
inline ofxPoint_<T> operator-( T f, const ofxPoint_<T>& vec ) {
    return ofxPoint_<T>( f-vec.x, f-vec.y, f-vec.z );
}
template < typename T >
inline ofxPoint_<T> operator*( T f, const ofxPoint_<T>& vec ) {
    return ofxPoint_<T>( f*vec.x, f*vec.y, f*vec.z );
}
template < typename T >
inline ofxPoint_<T> operator/( T f, const ofxPoint_<T>& vec ) {
    return ofxPoint_<T>( f/vec.x, f/vec.y, f/vec.z);
}
