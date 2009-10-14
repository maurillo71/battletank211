/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

/// Enable the use of M_PI, etc.
#define _USE_MATH_DEFINES
#include <cmath>

#ifdef PROJECT_engine
/// Export the classes for the engine DLL.
#	define DLL __declspec(dllexport)
#else
/// Import the classes from the engine DLL.
#	define DLL __declspec(dllimport)
#endif

/// An object in the arena with a position.
class DLL ArenaObject {
protected:
	ArenaObject() {}

public:
	/// \return The object's rectangular position x-coordinate, in squares.
	double GetXPosition() const { return px; }
	/// \return The object's rectangular position y-coordinate, in squares.
	double GetYPosition() const { return py; }
	/// \return The object's radius.
	double GetRadius() const { return radius; }
	
	/// Get the angle between this object and another object.
	/// \param other The other object.
	/// \return The angle, in radians counterclockwise from east.
	double GetAngleTo(const ArenaObject &other) const {
		return atan2(other.py-py, other.px-px);
	}
	/// Get the distance between this object and another object.
	/// \param other The other object.
	/// \return The distance, in squares.
	double GetDistanceTo(const ArenaObject &other) const {
		const double dx = other.px-px, dy = other.py-py;
		return sqrt(dx*dx + dy*dy);
	}

	/// \param deg An angle in degrees.
	/// \return The angle in radians.
	static double DegToRad(double deg) { return deg*M_PI/180; }
	/// \param rad An angle in radians.
	/// \return The angle in degrees.
	static double RadToDeg(double rad) { return rad*180/M_PI; }

protected:
	/// The object's rectangular position x-coordinate, in squares.
	double px;
	/// The object's rectangular position y-coordinate, in squares.
	double py;
	/// The object's radius.
	double radius;
};
