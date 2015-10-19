#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h> 
#include <time.h>  
#include "consts.h"
#include "GameState.h"
#include "string.h"

int blocks[21][3] = { {},{ 5,8,2 },{ 1, 10, 3 },{ 2, 12, 4 },{ 3, 14, 5 },
						 { 4, 6, 1 },{ 15, 5, 7 },{ 6, 17, 8 },{ 7, 1, 9 },
						 { 8, 18, 10 },{ 9, 2, 11 },{ 10, 19, 12 },{ 11, 3, 13 },
						 { 12, 20, 14 },{ 13, 4, 15  },{ 14, 16 ,6 },{ 20, 15, 17 },
						 { 16, 7, 18 },{ 17, 9, 19 },{ 18, 11, 20 },{ 19, 13, 16 } };

sfw::string blockNames[21]{ "","5th Street", "9th Street", "Salmon Street", "Loie Street", 
								"1st Street", "2nd Street", "3rd Street", "Shelmound Ave", 
								"7th Street", "8th Street", "Clear Ave", "Seabright Blvd", 
								"Miraloft Blvd", "Vinyl Street", "Hockinlens Ave", "Tubicolosis Ave", 
								"4th Street", "6th Street", "Rosebud Alley", "Ravenna Blvd"};

//help from terry
int clampInt(int lowerBound, int upperBound, int value)
{
	if (value < lowerBound) return lowerBound;
	if (value > upperBound) return upperBound;
	return value;
}


void GameState::play() {
	srand(time(NULL));
	

	win.playerAtExit = false;
	player1.caught = false;

	win.exitCurrentBlock = clampInt(10, 21, rand() % 10 + 12);
	player1.pCurrentBlock = 1;

	enemy.eCurrentBlock = clampInt( 2, 21, rand() % 21 + 2);
	enemy2.eCurrentBlock = clampInt(2, 21, rand() % 21 + 2);
	enemy3.eCurrentBlock = clampInt(2, 21, rand() % 21 + 2);

	win.displayBorder();
}

STATE GameState::update(){
	player1.movePlayer();

	win.winCheck(player1);
	if (win.playerAtExit == true) { return MAIN; }

	enemy.moveNpc();
	enemy2.moveNpc();

	player1.enemyCheck(enemy);
	if (player1.caught == true) { return MAIN; }
	player1.enemyCheck(enemy2);
	if (player1.caught == true) { return MAIN; }
	player1.enemyCheck(enemy2);
	if (player1.caught == true) { return MAIN; }

	return GAME;
}

void Border::displayBorder()
{
	std::cout << "The border is at: " << blockNames[exitCurrentBlock] << std::endl;
	std::cout << "Get there to escape" << std::endl;
}

void Border::winCheck(Player &player1)
{
	if (player1.pCurrentBlock == exitCurrentBlock) { playerAtExit = true; }
	else { playerAtExit = false; }

	if (playerAtExit == true){
		system("cls");
		std::cout << "You escaped!" << std::endl;
		system("pause");
	}
}


void Player::movePlayer()
{
	
	std::cout << "You are on " << blockNames[pCurrentBlock] << std::endl;
	std::cout << "Which street would you like to go to?" << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << i + 1 << ": " << blockNames[blocks[pCurrentBlock][i]] << std::endl;
	}
	pCurrentBlock = blocks[pCurrentBlock][getNumValid(1, 3) - 1];
	file.open("PlayerPath.txt", ios_base::out);
}

void Player::enemyCheck(Npc enemyOne)
{
	if (pCurrentBlock == enemyOne.eCurrentBlock) {
		caught = true;
		system("cls");
		std::cout << "You were caught! Try again?" << std::endl;
		system("pause");
	}
	// Help From Terry
	for (int i = 0; i < 3; ++i) {
		if (blocks[pCurrentBlock][i] == enemyOne.eCurrentBlock) {
			// wumpus nearby, print warning
			// break out of the loop
			std::cout << " It sounds like a platoon is nearby " << std::endl;
			break;
		}
	}
}

void Npc::moveNpc()
{
	int t = rand() % 3;
	eCurrentBlock = blocks[eCurrentBlock][t];

	//std::cout << "DEBUG: WUMPUS" << std::endl;
	//// print out the possibles rooms for the wumpus
	//for (int i = 0; i < 3; ++i)
	//{
	//	std::cout << i + 1 << ": " << blockNames[blocks[eCurrentBlock][i]] << std::endl;
	//}
}

int getLanguage(Player &One) {

	LANG Lang = English;
	int Temp = rand() % 3;

	switch (Temp) {
	case English:	Lang = English;
	case French:	Lang = French;
	case German:	Lang = German;
	}
	return Lang;
}

