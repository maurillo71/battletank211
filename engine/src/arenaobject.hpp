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
class ArenaObject {
public:
	/// \return The object's rectangular position x-coordinate, in squares.
	double GetXPosition() const { return px; }
	/// \return The object's rectangular position y-coordinate, in squares.
	double GetYPosition() const { return py; }

	/// \return The object's rectangular velocity x-coordinate, in squares per
	///         turn.
	double GetXVelocity() const { return speed*cos(heading); }
	/// \return The object's rectangular velocity y-coordinate, in squares per
	///         turn.
	double GetYVelocity() const { return speed*sin(heading); }
	
	/// \return The object's speed, in squares per turn.
	double GetSpeed() const { return speed; }
	/// \return The object's heading, in radians counterclockwise from east.
	double GetHeading() const { return heading; }

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
	/// Set up the displacement working variables.
	virtual void DisplaceSetup() {
		if (speed) {
			vx = GetXVelocity();
			vy = GetYVelocity();
		}
		else {
			vx = 0;
			vy = 0;
		}
	}

	/// Displace the position toward its destination.
	/// \param t The turn time, from 0 (turn start) to 1 (turn end).
	virtual void Displace(double t) {
		if (speed) {
			double td = t - told;
			px += vx*td;
			py += vy*td;
			told = t;
		}
	}

protected:
	/// The object's rectangular position x-coordinate, in squares.
	double px;
	/// The object's rectangular position y-coordinate, in squares.
	double py;
	/// The object's speed, in squares per turn.
	double speed;
	/// The object's heading, in radians counterclockwise from east.
	double heading;
	/// The object's rectangular x-coordinate of velocity in squares per turn.
	double vx;
	/// The object's rectangular y-coordinate of velocity in squares per turn.
	double vy;
	/// The old value of t used in Displace.
	double told;
	/// The object's energy.
	double energy;
};
