/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "arenaobject.hpp"

class MobileObject : public ArenaObject
{
protected:
	MobileObject() {}

public:
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
	double speed;
	/// The object's heading, in radians counterclockwise from east.
	double heading;
	/// The object's rectangular x-coordinate of velocity in squares per turn.
	double vx;
	/// The object's rectangular y-coordinate of velocity in squares per turn.
	double vy;
	/// The old value of t used in Displace.
	double told;
};
