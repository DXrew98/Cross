#pragma once
#include "Consts.h"
#include "string.h"


enum LANG {English, French, German};

struct Player {
	int pCurrentBlock;
	int food;
	bool gun;
	bool docOutfit;
	LANG playerLang = LANG;

	void movePlayer();
	int enemyCheck(Npc one);
};

struct Npc {
	int eCurrentBlock;

	void moveNpc();
};



class GameState
{
	Player player1;
	Npc enemy;
	Npc friendly;


public:
	void play();
	STATE update();
};