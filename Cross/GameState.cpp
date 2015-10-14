#include <iostream>
#include <cstdlib>
#include "consts.h"
#include "GameState.h"
#include "string.h"

int blocks[20][3] = { { 5,8,2 },{ 1, 10, 3 },{ 2, 12, 4 },{ 3, 14, 5 },
{ 4, 6, 1 },{ 7, 1, 9 },{ 8, 18, 10 },{ 9, 2, 11 },
{ 10, 19, 12 },{ 11, 3, 13 },{ 12, 20, 14 },{ 13, 4, 15 },
{ 14, 16, 6 },{ 15, 5, 7 },{ 6, 17, 8 },{ 16, 7, 18 },
{ 17, 9, 19 },{ 18, 11, 20 },{ 19, 13, 16 },{ 20, 15, 17 } };

sfw::string blockNames[20];

void GameState::play() {

	
}

STATE GameState::update(){

	

	system("pause");
	return MAIN;
}

void Player::movePlayer()
{
	std::cout << "Where would you like to go?" << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << i + 1 << ": " << blockNames[blocks[currentBlock][i]] << std::endl;
		std::cout << "==>" << std::endl;

		currentBlock = blocks[currentBlock][getNumValid(1, 3) - 1];
	}
}

