#include "mainFunctions.h"
using namespace std;


/*==== Global Variables ====*/
/* These are the global variables used for controling the program*/
int guesses = 5;															// Number of guesses the player has.  Can be changed in-game
int wins = 0;																// records the number of player wins
int losses = 0;																// records the number of playe losses


																			/*==== End Global Variables ====*/






/*==== Main Functions ====*/
/*	The following are the main functions for the program.  Here you can find the menus, the game loop,
	input switch, and the game modes.
*/

// Function for game menus
void header(char screen) {
	switch (screen) {
		// Normal Mode Menu
	case 'n':
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                                                |" << endl;
		cout << "|                   Normal Mode                  |" << endl;
		cout << "|                                                |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|               Wins: " << wins << "  Losses: " << losses << "               |" << endl;
		cout << "==================================================" << endl;
		break;

	case 'h':
		// Hard Mode Menu
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                                                |" << endl;
		cout << "|                     Hard Mode                  |" << endl;
		cout << "|                                                |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|               Wins: " << wins << "  Losses: " << losses << "               |" << endl;
		cout << "==================================================" << endl;
		break;

	case 'w':
		// Welcome Screen Menu
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                                                |" << endl;
		cout << "|          By: Jake Meredith & Heming Sun        |" << endl;
		cout << "|                                                |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                    Let's play!                 |" << endl;
		cout << "==================================================" << endl << endl;

		system("pause");
		system("cls");
		break;

	case 'm':
		// Main Game Menu
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|  Please Select an Option:                      |" << endl;
		cout << "|  1. Normal Mode                                |" << endl;
		cout << "|  2. Hard Mode                                  |" << endl;
		cout << "|  3. Options                                    |" << endl;
		cout << "|  4. Help                                       |" << endl;
		cout << "|  5. Quit                                       |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|               Wins: " << wins << "  Losses: " << losses << "               |" << endl;
		cout << "==================================================" << endl << endl;
		cout << ":> " << flush;
		break;

	case 'i':
		// Help Menu
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                                                |" << endl;
		cout << "|              Help and Instructions             |" << endl;
		cout << "|                                                |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|               Wins: " << wins << "  Losses: " << losses << "               |" << endl;
		cout << "==================================================" << endl << endl;
		break;
	case 'o':
		// Options Menu
		cout << "==================================================" << endl;
		cout << "|                The Alphabet Game               |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|                                                |" << endl;
		cout << "|                     Options                    |" << endl;
		cout << "|                                                |" << endl;
		cout << "|------------------------------------------------|" << endl;
		cout << "|               Wins: " << wins << "  Losses: " << losses << "               |" << endl;
		cout << "==================================================" << endl << endl;
		break;
	default:
		break;
	}


}



// Function for capturing user input.  Used for menu navigation
int getInput() {
	int input;
	cin >> input;

	switch (input) {
	case 1:							// user selects option 1, Normal Mode
		system("cls");				// clear console screen
		normalMode();				// normal mode function
		return 1;					// return 1 for main do-loop
		break;						// break switch
	case 2:							// user selects option 2, Hard Mode
		system("cls");				// clear console screen
		hardMode();					// hard mode function
		return 1;					// return 1 for main do-loop
		break;						// break switch
	case 3:							// user selects option 3, Options
		system("cls");				// clear console screen
		setGuesses();				// set guesses function
		return 1;					// return 1 for main do-loop
		break;						// break switch
	case 4:							// user selects option 4, help menu
		system("cls");				// clear console screen
		help();						// help menu function
		return 1;					// return 1 for main do-loop
		break;						// break switch
	case 5:							// user selects option 5, quit
		return 0;					// return 0 to break main do-loop
		break;						// break switch
	default:						// default case, used for integers > 5
		cout << "Please enter a valid option." << endl;
		return 1;					// return 1 for main do-loop
	}
}


// Function for setting the number of guesses.
void setGuesses() {
	cin.clear();
	cin.ignore();
	header('o');																					// displays the options header menu
	cout << "Here you can set the number of guesses you have before game over." << endl;
	cout << "Your current number of guesses will be displayed during gameplay." << endl << endl;
	cout << "Guesses set to: " << guesses << endl << endl;											// displays current guess setting
	cout << "Please set the number of guesses you would like (-1 for unlimited): " << flush;
	cin >> guesses;																					// user sets the number of guesses
}


// Function for the help menu
void help() {
	header('i');																					// displays the help header menu
	cout << "Welcome to The Alphabet Game!" << endl;
	cout << "This is a simple letter/character guessing game.  The computer will randomly choose a letter or character, it" << endl;
	cout << "is then up to you to guess the correct answer.  After guessing incorrectly, you will recieve a hint.  There are" << endl;
	cout << "two modes included with the game, Normal Mode and Hard Mode." << endl << endl << endl;

	cout << "Normal Mode - In this mode, the computer will only choose lower case letters in the alphabet.  You must" << endl;
	cout << "correctly guess the letter before you run out of guesses." << endl << endl << endl;

	cout << "Hard Mode - In this mode, the computer will randomly pick any character, letter, or symbol from the" << endl;
	cout << "ASCII table (between 33 and 126).  Using an ASCII table for help is recommended.  When a" << endl;
	cout << "hint is given, a \"-->\" means that the decimal of the corrisponding ASCII is greater than" << endl;
	cout << "your guess.  Likewise a \"<--\" means it is less than.  Use an ASCII table for help!" << endl << endl << endl;

	system("pause");
}




void hintScreen(string input) {
	stringstream ss;
	string border = "--------------------------------------------------";		// just a border, for formatting

	ss << endl << input << endl << endl << border << endl;
	cout << ss.str();
	ss.str("");
}

// Function for controling the game loop.
// For both normal and hard mode.
void gameLoop(char menu, int min, int max) {												// three arguments used to change the menu displayed, the lower bound on ASCII table, and upper bound.
	string gameOverWin = "You got it!!\nThe answer was: ";								// win statement
	string gameOverLose = "Game Over!\nYou Lose!!\nThe correct answer was: ";		// game over statement
	string hsWin = "\t\t     You Win!!";
	string hsLose = "\t\t     You Lose!";
	string wrongL = "\t\t  Incorrect. <--";										// hint left
	string wrongR = "\t\t  Incorrect. -->";										// hint right
	string numOfGuesses = "Guesses remaining: ";								// number of guesses
	string prevGuesses = "Previous Guesses: ";
	string error = "This is not supposed to happen....";
	string promptPlayer = "What is your guess?: ";

	stringstream gameTxt;															// a string stream is used to concatenate strings, chars, and ints into a single print statement
	stringstream ssPrevGuess;





	header(menu);																			// the display menu used

	random_device rd;																		// obtain a random number from the hardware
	mt19937 randomNum(rd());																// seed the generator
																							//	mt19937 randomNum(time(NULL));															// experimenting with time(NULL) as seed
	uniform_int_distribution<int> alphabetASCII(min, max);									// define the range

	char playerChoice = ' ';																// variable for player input
	char cpuChoice;																			// variable for the computer's choice
	int guessesLocal = guesses;																// sets the global guesses to a local variable for guesses, this way the global variable doesn't need to be altered.

	cpuChoice = alphabetASCII(randomNum);													// generates a random number, as ASCII decimal

	do {																					// do loop for game.  Will run if guessesLocal > 0 or guessesLocal < 0.
		if (guessesLocal == guesses) {
			hintScreen("");
		}

		//		cout << cpuChoice << endl;															// displays the answer.  Used for debugging.

		gameTxt << numOfGuesses << guessesLocal << endl;
		cout << gameTxt.str();
		gameTxt.str("");

		ssPrevGuess << playerChoice << " ";
		cout << prevGuesses << flush;
		cout << ssPrevGuess.str() << endl;

		cout << "What is your guess?: " << flush;											// Print statement.  Prompt for user input
		cin >> playerChoice;																// capture user input

		system("cls");
		header(menu);

		if (playerChoice == cpuChoice) {													// if player guesses correctly
			hintScreen(hsWin);
			gameTxt << gameOverWin << cpuChoice << endl << endl;									// String stream to concatenate win dialogue with the computer's choice
			cout << gameTxt.str();																// print statement for string stream
			gameTxt.str("");																		// empties the string stream
			++wins;																			// increment wins by 1.
			system("pause");																// wait for user input
			break;																			// breaks out of the do loop early
		}

		else if (playerChoice > cpuChoice) {												// if player's guess comes after computer's choice
			if ((guessesLocal > 1) || (guessesLocal < 0)) {									// a hint will only be given up to the player's last guess.
				hintScreen(wrongL);	// print statement for a hint, with some formatting
			}
			--guessesLocal;																	// decrement guesses by 1
		}

		else if (playerChoice < cpuChoice) {												// if player's guess comes before the computer's choice
			if ((guessesLocal > 1) || (guessesLocal < 0)) {									// a hint will only be given up to the player's last guess
				hintScreen(wrongR);			// print statement for a hint, with some formatting
			}
			--guessesLocal;																	// decrement guesses by 1
		}

		else {
			cout << error << endl << "Try again." << endl;	// else statement that should never happen
		}

		if (guessesLocal == 0) {															// when the player's guesses reach 0
			system("cls");
			++losses;																		// increment total losses by 1
			header(menu);
			hintScreen(hsLose);
			gameTxt << endl << gameOverLose << cpuChoice << endl << endl;							// string stream statment that includes game over screen along with the correct answer
			cout << gameTxt.str();																// prints out the string stream
			gameTxt.str("");																		// clears the string stream
			system("pause");																// pause, wait for user input
		}

	} while (guessesLocal != 0);															// breaks the do-loop when guesses == 0
	ssPrevGuess.str("");

}

void normalMode() {																			// function for normal mode
	gameLoop('n', 97, 122);																	// 'n' is for normal mode menu, 97 is lower bound, 122 is upper bound
}


void hardMode() {																			// function for hard mode
	gameLoop('h', 33, 126);																	// 'h' is for hard mode menu, 33 is lower bound, 126 is upper bound
}
/*==== End Main Functions ====*/