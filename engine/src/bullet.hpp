/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "arenaobject.hpp"

/// The class representing a bullet flying through the arena.
class Bullet : public ArenaObject {
public:
	/// \return The bullet's energy.
	double GetEnergy() const { return energy; }
};
