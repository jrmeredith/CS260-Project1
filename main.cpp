// Project 1 (Alphabet Game).cpp : Defines the entry point for the console application.
// By Jake Meredith & Heming Sun

#include "mainFunctions.h"									// main function header
using namespace std;										// using standard namespace; std::


int main()
{
	header('w');											// displays the Welcome Screen

	do {													// main do-loop for the program, this allows the program to run until the user quits
		system("cls");										// clear console screen every time the loop runs
		header('m');										// display Main Menu every time the loop runs

		if (cin.fail()) {									// if cin fails to capture; i.e. it expects an int and gets a char or string
			cin.clear();									// clear buffer
			cin.ignore(255, '\n');							// ignore upto 255 characters or until a newline
			cout << " Invalid input." << endl << endl;		// print out statement
			cout << ":> " << flush;							// for formatting and looks
		}
	} while (getInput());									// do-loop runs while getInput() returns a 1


	return 0;
}

