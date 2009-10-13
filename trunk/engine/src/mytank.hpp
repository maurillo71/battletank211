/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "tank.hpp"

/// This class represents the tank controlled by the user's own AI.
class MyTank : public Tank
{
protected:
	/// The constructor. Protected because this class is abstract (only
	/// children can be instantiated).
	MyTank() {}

public:
	/// This is called by the engine when it's your turn. This is the heart of
	/// the AI code.
	virtual void Think() = 0;
};
