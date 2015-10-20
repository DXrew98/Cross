#pragma once
#include <fstream>
#include "Consts.h"
#include "string.h"


enum LANG {English, French, German};



struct Npc {
	int eCurrentBlock;

	void moveNpc();
};

struct Player {
	int pCurrentBlock;
	int food;
	bool gun;
	bool docOutfit;
	bool caught;
	//LANG playerLang = LANG;

	void movePlayer();
	void enemyCheck(Npc one);
};

struct Border {
	
	bool playerAtExit;
	int exitCurrentBlock;

	void displayBorder();
	void winCheck(Player &player1);
};



class GameState
{
	Border win;
	Player player1;
	Npc enemy;
	Npc enemy2;
	Npc enemy3;


public:
	void play();
	STATE update();
};