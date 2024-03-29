/** \file
* \par Subversion URL:
* \$URL$
* \version \$Rev$
* \date    \$Date$
*/

#include <iostream>
#include <GL/glut.h>

#include "arena.hpp"

using namespace std;

/// The program's entry point.
/// \param argc The number of command-line arguments. glutInit might change this.
/// \param argv The command-line argument list. glutInit might change this.
/// \return The error level for the operating system.
int __cdecl main(int argc, char **argv) {
	glutInit(&argc, argv);

	Arena arena;

	return 0;
}
