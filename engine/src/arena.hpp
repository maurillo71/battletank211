/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include <list>

#include "bullet.hpp"
#include "mytank.hpp"
#include "bonus.hpp"

/// The class representing a battle arena and all of the objects that it
/// contains.
class Arena {
public:
	Arena();

	~Arena();

	/// Perform one arena turn.
	void DoTurn();

	/// Perform one tick within a turn.
	/// \param t The time, from 0 (turn start) to 1 (turn end).
	void Tick(double t);

private:
	/// The number of real-time seconds per turn.
	double spert;

	typedef std::list<Tank*> TankList;
	typedef std::list<Bullet> BulletList;
	typedef std::list<Bonus> BonusList;
	typedef std::list<ArenaObject*> ArenaObjectList;
	typedef std::list<MobileObject*> MobileObjectList;

	/// The list of tanks.
	TankList tanks;
	/// The list of bullets.
	BulletList bullets;
	/// The list of bonuses.
	BonusList bonuses;
	/// The list of all objects.
	ArenaObjectList objects;
	/// The list of all mobile objects.
	MobileObjectList mobiles;
};
