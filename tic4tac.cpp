// tic\4/tac
//
// a c++ tic-tac-toe application
//
// v- 1.02 bph- 2013

#include <iostream>

using namespace std;

// defines some functions to be used in the game
void welcome();
void nextTurn();
void currentBoard();
void endGame();

// defines some global variables
bool humanGame = false;
bool gameOver = false;
bool victory = false;
bool playeroneTurn = true;
string playeroneName, playertwoName;
string currentMove = "  ";
char playerOne, playerTwo;

// sets the game board to intially be blank
char a[] = "   ";
char b[] = "   ";
char c[] = "   ";

// the main commands
int main() {

	welcome();
	do {
		nextTurn();
	} while (gameOver == false);

	return 0;
}

// the welcome screen and game setup
void welcome() {

	int playtype = 0;
	cout << "\nWelcome to tic 4 tac!\n\nWhat type of game would you like to play?\n\n1. Human vs. Human\n2. Human vs. Computer\n" << endl;
		
	do {
		cin >> playtype;

		if (playtype != 1) {
			cout << "\nThat is not a valid option, please select again:\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (playtype != 1);

	// game setup for human vs. human
	if (playtype == 1) {
		humanGame = true;
		cout << "\n===============================" << endl;

		// gather the player's names
		cout << "\nPlease enter player one's name: ";
		cin >> playeroneName;
		cin.clear();
		cout << "Now enter player two's name: ";
		cin >> playertwoName;
		cin.clear();
		cout << "\n===============================" << endl;


		// player one get's to choose to be X or O
		cout << "\n" << playeroneName << ", would you like to be Xs or Os?  Please enter: ";
		cin >> playerOne;
		cin.get();

		// assigns player two to be the other option
		if (playerOne == 'X') {
			playerTwo = 'O';
		}
		if (playerOne == 'O') {
			playerTwo = 'X';
		}

		cout << "\nExcellent.  " << playeroneName << " will be " << playerOne << "s and " << playertwoName << " will be " << playerTwo << "s." << endl;
		cout << "\nGet ready to play!\n" << endl;
	}
}

// displaying the board as it currently stands
void nextTurn() {

	// shows the game board
	currentBoard();

	// specifies that so far a valid move has not been made this turn
	bool validMove = false;

	// player one's turn
	if (playeroneTurn == true) {	
		do {
			cout << playeroneName << ", please make a move: ";
			cin >> currentMove;

			// assigns the move, if valid, to one of the corresponding squares
			if ((currentMove.compare("A1") == 0 || currentMove.compare("1A") == 0) && a[0] == ' ') {
				a[0] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("A2") == 0 || currentMove.compare("2A") == 0) && a[1] == ' ') {
				a[1] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("A3") == 0 || currentMove.compare("3A") == 0) && a[2] == ' ') {
				a[2] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("B1") == 0 || currentMove.compare("1B") == 0) && b[0] == ' ') {
				b[0] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("B2") == 0 || currentMove.compare("2B") == 0) && b[1] == ' ') {
				b[1] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("B3") == 0 || currentMove.compare("3B") == 0) && b[2] == ' ') {
				b[2] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("C1") == 0 || currentMove.compare("1C") == 0) && c[0] == ' ') {
				c[0] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("C2") == 0 || currentMove.compare("2C") == 0) && c[1] == ' ') {
				c[1] = playerOne;
				validMove = true;
			}
			if ((currentMove.compare("C3") == 0 || currentMove.compare("3C") == 0) && c[2] == ' ') {
				c[2] = playerOne;
				validMove = true;
			}

			// if none of the valid moves apply, validMove is still false and player one is asked to try again
			if (validMove == false) {
				cout << currentMove << " is not a valid move, please try again." << endl;
			}
		} while (validMove == false);
		
		// checks to see if victory or a tie has been achieved
		endGame();
	}

	// player two's turn
	if (playeroneTurn == false) {
		do {
			cout << playertwoName << ", please make a move: ";
			cin >> currentMove;

			// assigns the move, if valid, to one of the corresponding squares
			if ((currentMove.compare("A1") == 0 || currentMove.compare("1A") == 0) && a[0] == ' ') {
				a[0] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("A2") == 0 || currentMove.compare("2A") == 0) && a[1] == ' ') {
				a[1] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("A3") == 0 || currentMove.compare("3A") == 0) && a[2] == ' ') {
				a[2] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("B1") == 0 || currentMove.compare("1B") == 0) && b[0] == ' ') {
				b[0] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("B2") == 0 || currentMove.compare("2B") == 0) && b[1] == ' ') {
				b[1] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("B3") == 0 || currentMove.compare("3B") == 0) && b[2] == ' ') {
				b[2] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("C1") == 0 || currentMove.compare("1C") == 0) && c[0] == ' ') {
				c[0] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("C2") == 0 || currentMove.compare("2C") == 0) && c[1] == ' ') {
				c[1] = playerTwo;
				validMove = true;
			}
			if ((currentMove.compare("C3") == 0 || currentMove.compare("3C") == 0) && c[2] == ' ') {
				c[2] = playerTwo;
				validMove = true;
			}

			// if none of the valid moves apply, validMove is still false and player two is asked to try again
			if (validMove == false) {
				cout << currentMove << " is not a valid move, please try again." << endl;
			}
		} while (validMove == false);

		// checks to see if victory or a tie has been achieved
		endGame();
	}

	// changes turns to the other player
	cout << endl;
	playeroneTurn = !playeroneTurn;
}

void currentBoard() {
	// shows the board as it currently stands
	cout << "__|_____|_____|_____|__" << endl;
	cout << "  |     |     |     |  " << endl;
	cout << "  |  " << a[2] << "  |  " << b[2] << "  |  " << c[2] << "  | 3" << endl;
	cout << "__|_____|_____|_____|__" << endl;
	cout << "  |     |     |     |  " << endl;
	cout << "  |  " << a[1] << "  |  " << b[1] << "  |  " << c[1] << "  | 2" << endl;
	cout << "__|_____|_____|_____|__" << endl;
	cout << "  |     |     |     |  " << endl;
	cout << "  |  " << a[0] << "  |  " << b[0] << "  |  " << c[0] << "  | 1" << endl;
	cout << "__|_____|_____|_____|__" << endl;
	cout << "  |  A  |  B  |  C  |  \n" << endl;
}

// function used to see if the game is over
void endGame() {

	// determines if one of the player's has won the game by checking to see if there is a three-in-a-row
	if ((a[0] != ' ' && a[0] == a[1] && a[1] == a[2]) || (b[0] != ' ' && b[0] == b[1] && b[1] == b[2]) || (c[0] != ' ' && c[0] == c[1] && c[1] == c[2]) || (a[0] != ' ' && a[0] == b[0] && b[0] == c[0]) || (a[1] != ' ' && a[1] == b[1] && b[1] == c[1]) || (a[2] != ' ' && a[2] == b[2] && b[2] == c[2]) || (a[0] != ' ' && a[0] == b[1] && b[1] == c[2]) || (a[2] != ' ' && a[2] == b[1] && b[1] == c[0])) {
		
		// declares the game over and states that a victory has occurred
		gameOver = true;
		victory = true;

		if (playeroneTurn == true) {
						
			// shows the final game board
			cout << endl;
			currentBoard();
			cout << "Congratulations, " << playeroneName << ", you are the winner!" << endl;
		}
		if (playeroneTurn == false) {

			// shows the final game board
			cout << endl;
			currentBoard();
			cout << "Congratulations, " << playertwoName << ", you are the winner!" << endl;
		}
	}

	// checks to see if a cats game has occurred
	if (a[0] != ' ' && a[1] != ' ' && a[2] != ' ' && b[0] != ' ' && b[1] != ' ' && b[2] != ' ' && c[0] != ' ' && c[1] != ' ' && c[2] != ' ' && victory == false) {

		// declares the game over and notifies that a tie has occurred
		gameOver = true;

		// shows the final game board
		cout << endl;
		currentBoard();
		cout << "Cats game!\n\nThe game has resulted in a tie.  Thank you both for playing!" << endl;
	}
}
