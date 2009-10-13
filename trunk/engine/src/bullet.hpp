/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "mobileobject.hpp"

/// The class representing a bullet flying through the arena.
class Bullet : public MobileObject {
public:
	/// \return The bullet's energy.
	double GetDamage() const { return damage; }
private:
	/// The damage the bullet will do on contact.
	double damage;
};
