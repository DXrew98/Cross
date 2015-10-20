#include <iostream>
#include <malloc.h>
#include <fstream>
#include "string.h"
#include "GameState.h"
#include "Consts.h"
#include "string.h"



int main() {
	GameState g;
	STATE current = SPLASH;


	while (true) {
		switch (current) {
		case SPLASH:splash();
		case MAIN:	current = mainMenu(); break;
		case PLAY:	g.play();
		case GAME:	current = g.update(); break;
		case EXIT:	exit(); return 0;
		}
	}
}
