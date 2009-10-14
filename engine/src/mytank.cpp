/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#include "mytank.hpp"

void MyTank::Limit(double x, double &y, double xmax) {
	if (x > xmax) y = xmax;
	else if (x < -xmax) y = -xmax;
	else y = x;
}
