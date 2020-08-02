#include <iostream>
#include <string>

bool running = true;
class Gameboard {
public:
	char board[5][5], enemyBoard[5][5];
	int inputX;
	int inputY;
	int hits = 0, misses = 0;
	
	Gameboard() {
		emptyGameBoard();
		printGameBoard();
		placeEnemyShips();
	}
	
	void emptyGameBoard() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				board[i][j] = '.';
				enemyBoard[i][j] = '.';
			}
		}
	}

	void printGameBoard() {
		std::cout << "012345\n";
		for (int i = 0; i < 5; i++) {
			i++;
			std::cout << i;
			i--;
			for (int j = 0; j < 5; j++) {
				std::cout << board[i][j];
			}
			std::cout << "\n";
		}
	}

	void input() {
		std::cout << "\nEnter two numbers to fire at (x y): ";
		std::cin >> inputX >> inputY;
		inputX--;
		inputY--;
		if (inputX > 4 || inputY > 4) {
			std::cout << "\nOut of bounds input! Defaulting to 1 1\n";
			inputX = 0;
			inputY = 0;
		}
		if (std::cin.fail()) {
			std::cerr << "Enter a number\n";
			running = false;
		}
	}

	void placeGameboardPieces() {
		if (enemyBoard[inputY][inputX] == '.') {
			board[inputY][inputX] = 'O';
			enemyBoard[inputY][inputX] = 'O';
			misses++;
		}
		else if (enemyBoard[inputY][inputX] == 'S') {
			board[inputY][inputX] = 'X';
			enemyBoard[inputY][inputX] = ' ';
			hits++;
		}
		else if (enemyBoard[inputY][inputX] == 'O' || enemyBoard[inputY][inputX] == ' ') {
			std::cout << "\nYou already shot at there!\n";
		}
	}

	void placeEnemyShips() {
		for (int i = 0; i < 6; i++) {
			enemyBoard[rand() % 5][rand() % 5] = 'S';
		}
	}

	void gameEnd() {
		std::cout << "\nYou had " << misses << " misses. Play again? Y or N: ";
		char YorN;
		std::cin >> YorN;
		if (std::cin.fail()) {
			std::cerr<<"Enter a letter!";
		}
		else if (YorN == 'Y') {
			running = true;
			emptyGameBoard();
			placeEnemyShips;
			printGameBoard();
		}
		else {
			running = false;
		}
	}
};

int main()
{	
	Gameboard gameboard;
	while (running) {
		gameboard.input();
		gameboard.placeGameboardPieces();
		gameboard.printGameBoard();
		if (gameboard.hits == 5) {
			gameboard.gameEnd();
		}
	}
}