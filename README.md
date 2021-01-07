# PhysiX Engine

This is a simple game coded in C inspired of "The World of Goo"

It's currently working only for Linux but a ".exe" will be pushed soon !

# Information

If you want to customize the game, run the file "index.html" in the repistories : Doxygen/html/

The file "physics.bin" is compiled for Linux so if you want to play the game, you need to open a terminal and write this command in the current repistory : ./physics.bin

# Build

First of all you'll need to install SDL2, open a terminal and write this :

[1] sudo apt-get update
[2] sudo apt-get upgrade
[3] sudo apt-get install libsdl2-dev

To compile open a terminal in the same folder where you have put all the game files :

- Compilation command : gcc main.c physics.c vector.c window.c timer.c scene.c renderer.c camera.c -o physics.bin -lm -lSDL2

- Launch command : ./physics.bin

// SOME INFOS ABOUT DOC SOON //

Some implementation for the game will be pushed soon :)
