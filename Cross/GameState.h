#pragma once
#include "Consts.h"
#include "string.h"




struct Player {
	int currentBlock;
	int food;
	bool gun;
	bool docOutfit;

	void movePlayer();
};

class Npc {

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