/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#include "mobileobject.hpp"

void MobileObject::DisplaceSetup() {
	if (speed) {
		vx = GetXVelocity();
		vy = GetYVelocity();
	}
	else {
		vx = 0;
		vy = 0;
	}
}

void MobileObject::Displace(double t) {
	if (speed) {
		double td = t - told;
		px += vx*td;
		py += vy*td;
		told = t;
	}
}
