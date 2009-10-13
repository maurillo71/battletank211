/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include <list>

#include "bullet.hpp"
#include "tank.hpp"
#include "bonus.hpp"

/// The class representing a battle arena and all of the objects that it
/// contains.
class Arena {
private:
	/// The number of real-time seconds per turn.
	double spert;

	std::list<Tank> tanks;
	std::list<Bullet> bullets;
	std::list<Bonus> bonuses;
};
