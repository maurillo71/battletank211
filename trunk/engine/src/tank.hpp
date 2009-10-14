/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#define STRICT
#include <windows.h>

#include "bullet.hpp"

/// This class represents any tank, regardless of whether it's yours or someone
/// else's.
class DLL Tank : public MobileObject {
protected:
	Tank() {}

public:
	/// \return The tank turret's heading, in radians counterclockwise from east.
	double GetTurretHeading() const { return turretheading; }

	/// Gets the heading to another object relative to the base of this tank.
	/// \param other The other arena object.
	/// \return The heading angle, in radians counterclockwise.
	double GetHeadingTo(const ArenaObject &other) const {
		return GetHeading() - GetAngleTo(other);
	}

	/// \return True if the tank's health is zero.
	bool IsDead() const { return !health; }

	/// This is called by the engine when it's your turn. This is the heart of
	/// the AI code.
	virtual void Think() = 0;

protected:
	/// Stop the motion of this tank.
	void Stop() {
		baseheadingd = 0;
		turretheadingd = 0;
		speed = 0;
	}

	/// Set up a displacement.
	virtual void DisplaceSetup() {
	}

	/// Displace this tank.
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

	/// The handle to the DLL in which the user code exists for this tank.
	HMODULE dll;

private:
	/// Allow the Arena access to the internals of this class.
	friend Arena;
};
