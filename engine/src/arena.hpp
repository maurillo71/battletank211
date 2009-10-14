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
class DLL Arena {
public:
	Arena();

	~Arena();

	/// Perform one arena turn.
	void DoTurn();

	/// Perform one tick within a turn.
	/// \param t The time, from 0 (turn start) to 1 (turn end).
	void Tick(double t);

private:
	/// A list of tanks. Pointers, for polymorphism; elements must be deleted
	/// by the arena.
	typedef std::list<Tank*> TankList;
	/// A list of bullets. Elements are owned by the list.
	typedef std::list<Bullet> BulletList;
	/// A list of bonuses. Elements are owned by the list.
	typedef std::list<Bonus> BonusList;
	/// A list of arena objects. This must be synchronized with tanks, bullets
	/// and bonuses.
	typedef std::list<ArenaObject*> ArenaObjectList;
	/// A list of mobile arena objects. This must be synchronized with tanks
	/// and bullets.
	typedef std::list<MobileObject*> MobileObjectList;

	/// The number of real-time seconds per turn.
	double spert;

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
