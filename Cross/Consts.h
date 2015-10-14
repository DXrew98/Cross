#pragma once
#include "string.h"

//Different states set tp 1 - 5
enum STATE { SPLASH, MAIN, PLAY, GAME, EXIT };

//Main menu presented
STATE mainMenu();

//Shows Splash Screen
void splash();

//Exits program
void exit();

//Use of Esme's modified valid num checker from FileIO
int getNumValid(int min, int max);