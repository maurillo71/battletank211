/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "bullet.hpp"

/// This class represents any tank, regardless of whether it's yours or someone
/// else's.
class Tank : public MobileObject {
public:
	/// \return The tank turret's heading, in radians counterclockwise from east.
	double GetTurretHeading() const { return turretheading; }

	/// \return The heading to another object relative to the base of this
	/// tank, in radians counterclockwise.
	double GetHeadingTo(const ArenaObject &other) const {
		return GetHeading() - GetAngleTo(other);
	}

protected:
	virtual void DisplaceSetup() {
	}

	virtual void Displace()	{
	}

	/// Take a hit from a bullet.
	/// \param b A reference to the bullet.
	void Hit(Bullet &b) {
		health -= b.GetDamage();
		if (health < 0)
			health = 0;
	}

protected:
	/// The tank's turret heading, in radians counterclockwise from east.
	double turretheading;
	/// The tank's base heading angular velocity in radians per turn
	/// counterclockwise.
	double baseheadingd;
	/// The tank's turrent heading angular velocity in radians per turn
	/// counterclockwise.
	double turretheadingd;

	/// The tank's health, from 0 to hmax.
	double health;
	/// The tank's energy, from 0 to emax.
	double energy;

	/// The energy consumed per unit of speed.
	double epers;
	/// The damage done by bullets fired by this tank per unit of bullet
	/// energy.
	double dpere;
	/// The energy regenerated per turn.
	double epert;
	/// The maximal health.
	double hmax;
	/// The maximal energy.
	double emax;
	/// The maximal speed.
	double smax;
	/// The maximal base rotation angle, in radians counterclockwise.
	double rbasemax;
	/// The maximal turrent rotation angle, in radians counterclockwise.
	double rturretmax;
};
