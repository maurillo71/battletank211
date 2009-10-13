/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#pragma once

#include "arenaobject.hpp"

/// This class represents any tank, regardless of whether it's yours or someone
/// else's.
class Tank : public ArenaObject
{
public:
	/// \return The tank's heading, in radians counterclockwise from east.
	double GetHeading() const { return heading; }

	/// \return The heading to another object relative to this tank, in radians
	///         counterclockwise from east.
	double GetHeadingTo(const ArenaObject &other) const {
		return heading - GetAngleTo(other);
	}
private:
	/// The tank's heading, in radians counterclockwise from east.
	double heading;
};
