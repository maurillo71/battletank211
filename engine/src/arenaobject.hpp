/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

/// An object in the arena with a position, velocity vector, etc.
class ArenaObject
{
public:
	/// \return The object's rectangular position x-coordinate.
	double GetXPosition() const { return px; }
	/// \return The object's rectangular position y-coordinate.
	double GetYPosition() const { return py; }
	/// \return The object's rectangular velocity x-coordinate.
	double GetXVelocity() const { return vx; }
	/// \return The object's rectangular velocity y-coordinate.
	double GetYVelocity() const { return vy; }

	/// Get the angle between this object and another object.
	/// \param other The other object.
	/// \return The angle, in radians.
	double GetAngleTo(const ArenaObject &other) const {
		return atan2(other.py-py, other.px-px);
	}

	/// \param deg An angle in degrees.
	/// \return The angle in radians.
	static double DegToRad(double deg) { return deg*M_PI/180; }
	/// \param rad An angle in radians.
	/// \return The angle in degrees.
	static double RadToDeg(double rad) { return rad*180/M_PI; }

private:
	/// The object's rectangular position x-coordinate.
	double px;
	/// The object's rectangular position y-coordinate.
	double py;
	/// The object's rectangular velocity x-coordinate.
	double vx;
	/// The object's rectangular velocity y-coordinate.
	double vy;
};
