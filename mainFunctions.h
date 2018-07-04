#pragma once
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <iostream>		// used for cin, cout, etc
#include <string>		// used for strings
#include <ctime>		// used for time(NULL)
#include <sstream>		// used to create string streams
#include <random>		// used for random number generation

void header(char screen);						// Game Menus

int getInput();									// allows for menu navigation

void gameLoop(char menu, int min, int max);		// used to control flow of the game.  Used for both Normal and Hard
void normalMode();								// uses the arguments from gameLoop() to generate a normal game
void hardMode();								// uses the arguments from gameLoop() to generate a hard game
void setGuesses();								// used for setting number of guesses.  User can change setting
void help();									// help screen that describes the game and normal and hard mode
void hintScreen(std::string input);

#endif // !MAINFUNCTIONS_H