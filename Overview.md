# Overview #

This project is a combination of a game and an opportunity to learn programming in C++. It is very similar to [Robocode](http://robocode.sourceforge.com), but since the course with which this project is associated uses C++, we can't use Robocode because that uses Java. Plus, making something from scratch is fun.

The idea is for students to write programs that control virtual robotic tanks. These tanks try to kill each other. Maybe they're robots gone wrong, maybe they're instruments of opposing military forces in some sort of epic battle, or maybe they've just had a bad day.

The goal of this project is to get students to see how programming can be interesting and not just applicable to math and science.

# Sections #

The project code will exist in three chunks. The first chunk will be a quickie interface in C# to configure arena parameters. The second chunk will be the actual game code that tracks the tanks, uses OpenGL graphics and sound effects. The third chunk is what students have to do: a tiny sub-program that controls a tank's AI. There will be a lot of built-in functions to make this job easier, and I'll also provide a bunch of different sample AIs.

# Building #

Currently, to build the code, you need Windows and the following software:
  * [OpenGL win32 port by Nate Robins](http://www.xmission.com/~nate/glut.html) - make sure that this is visible from the code. If you plan on using it elsewhere, dump it in a public folder and add it to Tools > Options > Projects and Solutions > VC++ directories > Win32 include files. Otherwise just dump it locally.
  * [Microsoft Visual C++ Express 2008](http://www.microsoft.com/express)
  * Any subversion client. [TortoiseSVN](http://tortoisesvn.tigris.org) is good

The "engine" project builds a .dll that contains the basic game structure code; all other binaries will rely on this. The "gamegui" project builds an .exe that contains the graphics code and essentially displays the engine. All of the "`tank_*`" projects contain example tanks. To make your own, it's easiest to just copy one of these, rename it, gut it and replace the code with your own. Each tank project builds a `tank_*.dll`, and the engine scans for this pattern so make sure that it's named in the same way.

To build the documentation, you need
  * [Doxygen](http://www.stack.nl/~dimitri/doxygen)
  * [Graphviz](http://www.graphviz.org/)

Once you have those, just set the solution configuration to "doc" and build.

# Tournament #

The tournament will probably be open to participation from first- and second-year University of Windsor undergraduate students. Students from my 6-85-211-01 Computer-Aided Analysis II class are especially encouraged to give it a shot.

The tournament will probably happen at the end of the semester. If we're lucky and gather enough participants, we might be able to hold the tournament during class or lab hours. If not, we can always schedule a room somewhere else.

Currently I'm on the hunt for sponsors that could supply prizes for the competition winners. No matter what, I'm fronting a cash prize out of my own pocket whose size will depend on the eventual popularity of this contest.