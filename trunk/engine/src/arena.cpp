/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#include "arena.hpp"

Arena::Arena() {
	HMODULE dll = LoadLibrary("sittingduck.dll");
	typedef MyTank *(__cdecl *const InstProc)();
	InstProc GetNewUserTank = (InstProc)GetProcAddress(dll, "GetNewUserTank");
	MyTank *const newtank = GetNewUserTank();
	newtank->dll = dll;
	tanks.push_back(newtank);
}

Arena::~Arena() {
	HMODULE dll = tanks.front()->dll;
	delete tanks.front();
	tanks.pop_front();
	const BOOL success = FreeLibrary(dll);
}

void Arena::DoTurn() {
	// Make all tanks think
	for (TankList::iterator i = tanks.begin(); i != tanks.end(); i++)
		(*i)->Think();
}

void Arena::Tick(double t) {
	// Displace all mobile objects
	for (MobileObjectList::iterator i = mobiles.begin(); i != mobiles.end(); i++)
		(*i)->Displace(t);

	// Check for collisions between tanks and bullets
	for (TankList::iterator tank = tanks.begin(); tank != tanks.end();) {
		for (BulletList::iterator bullet = bullets.begin();;) {
			if (bullet == bullets.end()) {
				tank++;
				break;
			}
			if (bullet->GetDistanceTo(**tank) < bullet->GetRadius() + (*tank)->GetRadius()) {
				(*tank)->Hit(*bullet);
				bullet = bullets.erase(bullet);
				if ((*tank)->IsDead()) {
					delete *tank;
					objects.remove(*tank);
					mobiles.remove(*tank);
					tank = tanks.erase(tank);
					break;
				}
			}
			else bullet++;
		}
	}

	// Check for collisions between tanks
	for (TankList::iterator tank1 = tanks.begin();; tank1++) {
		TankList::iterator tank2 = tank1;
		if (++tank2 == tanks.end()) break;
		for (; tank2 != tanks.end(); tank2++) {
			if (tank1 == tank2) continue;
			if ((*tank1)->GetDistanceTo(**tank2) < (*tank1)->GetRadius() + (*tank2)->GetRadius()) {
				(*tank1)->Stop();
				(*tank2)->Stop();
			}
		}
	}
}
