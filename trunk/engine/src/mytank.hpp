/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "tank.hpp"

/// This class represents the tank controlled by the user's own AI.
class MyTank : public Tank {
protected:
	/// The constructor. Protected because this class is abstract (only
	/// children can be instantiated).
	MyTank() {}

public:
	/// This is called by the engine when it's your turn. This is the heart of
	/// the AI code.
	virtual void Think() = 0;

	/// Limit a variable to within [-xmax, xmax].
	/// \param x The variable to limit.
	/// \param y The variable that will get the limited value.
	/// \param xmax The limit.
	static void Limit(double x, double &y, double xmax) {
		if (x > xmax) y = xmax;
		else if (x < -xmax) y = -xmax;
		else y = x;
	}

	/// Rotate the tank's base. Repeated calls to this function within a single
	/// turn have no effect. The angle is limited by LimitRotation.
	/// \param rad The rotation angle, in radians counterclockwise.
	void RotateBaseBy(double rad) {
		Limit(rad, baseheadingd, rbasemax);
	}

	/// Rotate the tank's turret. Repeated calls to this function within a
	/// single turn have no effect. The angle is limited by LimitRotation.
	/// \param rad The rotation angle, in radians counterclockwise.
	void RotateTurretBy(double rad) {
		Limit(rad, turretheadingd, rturretmax);
	}

	/// Move the tank forward by the specified distance toward the tank base's
	/// heading. If the tank runs out of energy it will stop. If the speed is
	/// negative the tank will go in reverse. Repeated calls to this function
	/// in a single turn have no effect.
	/// \param s The speed for this turn, in squares per turn.
	void Move(double s) {
		Limit(s, speed, smax);
	}
};
