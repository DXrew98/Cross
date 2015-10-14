#include "consts.h"
#include "string.h"
#include <iostream>



//Main menu presented
STATE mainMenu() {

	system("cls");
	std::cout << "Welcome to CROSS!" << std::endl;
	std::cout << "1: Start a new a game" << std::endl;
	std::cout << "2: Back to Splash " << std::endl;
	std::cout << "3: Exit Game" << std::endl;

	switch(getNumValid(1,3))
	{
	case 1: return PLAY;
	case 2: return SPLASH;
	case 3:	return EXIT;
	}
}

//Shows Splash Screen
void splash() {
	system("cls");
	std::cout << "----------------------------------------------|-->" << std::endl;
	std::cout <<"   ____    _____     _____     _____   _____  | "	 << std::endl;
	std::cout <<" //       ||   \\\\   //   \\\\   //      //      |"    << std::endl;
	std::cout <<"||        ||___//  ||     ||  \\\\__    \\\\__    |"    << std::endl;
	std::cout <<"||        ||  \\\\   ||     ||      \\\\      \\\\  |"    << std::endl;
	std::cout <<" \\\\____   ||   \\\\   \\\\___//   ____//  ____//  |"    << std::endl;
	std::cout << "                                              |" << std::endl;
	std::cout <<"----------------------------------------------|-->" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "A game by Andrew Ward, andrew.ward@students.aie.edu.au" << std::endl;
	std::cout << "10/13/2015" << std::endl;
	system("pause");
	system("cls");
}
//Exits program
void exit() {
	system("cls");
	std::cout << "Thanks for playing!" << std::endl;
	std::cout << std::endl;
	system("pause");
}

//Use of Esme's modified valid num checker from FileIO
int getNumValid(int min, int max) {

	int select;
	do
	{
		std::cout << "Enter a valid number" << std::endl;
		std::cin >> select;


		std::cin.clear();
		std::cin.ignore(80, '\n');
		if (std::cin.fail() || select < min || select > max)
		{

			std::cout << "Invalid Entry" << std::endl;
		}
		else break;
	} while (true);

	return (select);
}