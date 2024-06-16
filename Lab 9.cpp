//William McAllister
//Lab 9
//Tic-Tac-Toe
//CSE 130-01A
//March 29, 2024

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::srand;
using std::rand;
using std::time;
using std::cout;
using std::cin;

char board[3][3];
bool botNeedsToMove = true;


void printBoard(void) {
	cout << "\n";
	cout << "  A   B   C\n";
	for(int i = 0; i < 3; i++) {
		cout << i << " " << board[0][i] << " | " << board[1][i] << " | " << board[2][i];
		if(i < 2) {
			cout << "\n ---+---+---\n";
		}
	}
}

void randBotPath(void) {
    bool botNeedsMoved = true;
    while(botNeedsMoved) {
        int randCol = rand() % 3;
        int randRow = rand() % 3;
        if(board[randCol][randRow] == ' ' && botNeedsToMove) {
            board[randCol][randRow] = 'O';
            botNeedsMoved = false;
    		botNeedsToMove = false;
        }
    }
}


bool checkWin(char lett) {
	for(int i = 0; i < 3; i++) {
		if(board[0][i] == lett && board[1][i] == lett && board[2][i] == lett) {
			return true;
		}
	}
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == lett && board[i][1] == lett && board[i][2] == lett) {
			return true;
		}
	}
	if(board[0][0] == lett && board[1][1] == lett && board[2][2] == lett) {
		return true;
	}
	if(board[0][2] == lett && board[1][1] == lett && board[2][0] == lett) {
		return true;
	}
	return false;
}

bool checkTie(void) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

bool needsBlock(void) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if((board[i][j] == 'X' && board[i + 1][j] == 'X') && i != 2) {
				if(board[i + 2][j] == ' ') {
					board[i + 2][j] = 'O';
					//cout << "\n1\n";
					return true;
				}
				if(board[i - 1][j] == ' ') {
					board[i - 1][j] = 'O';
					//cout << "\n2\n";
					return true;
				}
			}
			if(i == 0 && board[i][j] == 'X' && board[i + 2][j] == 'X' && board[i + 1][j] == ' ') {
				board[i + 1][j] = 'O';
				//cout << "\n3\n";
				return true;
			}
			if(j == 0 && board[i][j] == 'X' && board[i][j + 2] == 'X' && board[i][j + 1] == ' ') {
				board[i][j + 1] = 'O';
				//cout << "\n4\n";
				return true;
			}
			if(((board[i][j] == 'X' && board[i][j + 1] == 'X') && i != 2) && (board[i][j + 2] == ' ' || board[i][j - 1] == ' ')) {
				if(board[i][j + 2] == ' ' && j < 2) {
					board[i][j + 2] = 'O';
					//cout << "\n5\n";
					return true;
				}
				if(board[i][j - 1] == ' ' && j > 0) {
					board[i][j - 1] = 'O';
					//cout << "\n6\n";
					return true;
				}
			}
		}
	}
	if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == ' ') {
		board[2][2] = 'O';
		//cout << "\n7\n";
		return true;
	}
	if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == ' ') {
		board[2][0] = 'O';
		//cout << "\n8\n";
		return true;
	}
	if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == ' ') {
		board[0][2] = 'O';
		//cout << "\n9\n";
		return true;
	}
	if(board[2][2] == 'X' && board[1][1] == 'X' && board[0][0] == ' ') {
		board[0][0] = 'O';
		//cout << "\n10\n";
		return true;
	}
	return false;
}

bool easyWin(void) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if((board[i][j] == 'O' && board[i + 1][j] == 'O' && i != 2)) {
				if(board[i + 2][j] == ' ') {
					board[i + 2][j] = 'O';
					//cout << "\n1\n";
					return true;
				}
				if(board[i - 1][j] == ' ') {
					board[i - 1][j] = 'O';
					//cout << "\n2\n";
					return true;
				}
			}
			if(i == 0 && board[i][j] == 'O' && board[i + 2][j] == 'O' && board[i + 1][j] == ' ') {
				board[i + 1][j] = 'O';
				//cout << "\n3\n";
				return true;
			}
			if(j == 0 && board[i][j] == 'O' && board[i][j + 2] == 'O' && board[i][j + 1] == ' ') {
				board[i][j + 1] = 'O';
				//cout << "\n4\n";
				return true;
			}
			if(((board[i][j] == 'O' && board[i][j + 1] == 'O') && i != 2) && (board[i][j + 2] == ' ' || board[i][j - 1] == ' ')) {
				if(board[i][j + 2] == ' ') {
					board[i][j + 2] = 'O';
					//cout << "\n5\n";
					return true;
				}
				if(board[i][j - 1] == ' ') {
					board[i][j - 1] = 'O';
					//cout << "\n6\n";
					return true;
				}
			}
		}
	}
	if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == ' ') {
		board[2][2] = 'O';
		//cout << "\n7\n";
		return true;
	}
	if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == ' ') {
		board[2][0] = 'O';
		//cout << "\n8\n";
		return true;
	}
	if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == ' ') {
		board[0][2] = 'O';
		//cout << "\n9\n";
		return true;
	}
	if(board[2][2] == 'O' && board[1][1] == 'O' && board[0][0] == ' ') {
		board[0][0] = 'O';
		//cout << "\n10\n";
		return true;
	}
	return false;
}

int main(void) {
	int movesMade = 0;
	int botPath = 0;
	int ogCornerCol;
	int ogCornerRow;
	int col;
	char colL;
	int row;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	srand(time(0));
	int whoseMove = rand() % (2 - 1 + 1) + 1;
	//whoseMove = 1;
	printBoard();
	while(true) {
		if(whoseMove == 1) {
			cout << "\n\nYour turn!";
			cout << "\nWhat column do you want to make a move in? (A, B, C): ";
			cin >> colL;
			cout << "\nWhat row do you want to make a move in? (0, 1, 2): ";
			cin >> row;
			if(colL == 'A') {
				col = 0;
			} else if(colL == 'B') {
				col = 1;
			} else if(colL == 'C') {
				col = 2;
			} else {
				col = 3;
			}
			if(board[col][row] == ' ' && col <= 2 && col >= 0 && row <= 2 && row >= 0) {
				board[col][row] = 'X';
				whoseMove = 2;
				movesMade++;
			} else {
				cout << "Invalid space";
			}
		} else if(whoseMove == 2) {
			botNeedsToMove = true;
			cout << "\n\nBot's turn!\n";
			if(easyWin() && botNeedsToMove) {
				//cout << "\neasyWin\n";
				botNeedsToMove = false;
			} else if (needsBlock() && botNeedsToMove) {
				//cout << "\nneedsBlock\n";
				botNeedsToMove = false;
			} else {
				if(movesMade == 0 && botNeedsToMove) {
					int randCol = rand() % 2;
					int randRow = rand() % 2;
					//cout << randCol << "\n";
					//cout << randRow << "\n";
					if(randCol == 1) {
						ogCornerCol = 2;
					} else {
						ogCornerCol = 0;
					}
					if(randRow == 1) {
						ogCornerRow = 2;
					} else {
						ogCornerRow = 0;
					}
					board[ogCornerCol][ogCornerRow] = 'O';
					botNeedsToMove = false;
					botPath = 1;
				}
				//cout << "\n" << botNeedsToMove << "\n";
				if(movesMade == 1 && botNeedsToMove) {
					//cout << "here?\n";
					if((board[0][1] == 'X' || board[1][0] == 'X' || board[1][2] == 'X' || board[2][0] == 'X') && board[1][1] == ' ' && botNeedsToMove) {
						board[1][1] = 'O';
						botNeedsToMove = false;
					} else if(botPath == 1 && botNeedsToMove) {
						if(ogCornerCol == 0 && ogCornerRow == 0 && botNeedsToMove) {
							if(board[0][2] == ' ' && botNeedsToMove) {
								board[0][2] = 'O';
								botNeedsToMove = false;
								//cout << "1\n";
							} else if(board[2][0] == ' ' && botNeedsToMove){
								board[2][0] = 'O';
								botNeedsToMove = false;
								//cout << "2\n";
							} else {
								botPath = 2;
								//cout << "3\n";
							}
						} else if(ogCornerCol == 2 && ogCornerRow == 2 && botNeedsToMove) {
							if(board[0][2] == ' ' && botNeedsToMove) {
								board[0][2] = 'O';
								botNeedsToMove = false;
								//cout << "4\n";
							} else if(board[2][0] == ' ' && botNeedsToMove){
								board[2][0] = 'O';
								botNeedsToMove = false;
								//cout << "5\n";
							} else if(botNeedsToMove) {
								botPath = 2;
								//cout << "6\n";
							}
						} else if(ogCornerCol == 0 && ogCornerRow == 2 && botNeedsToMove) {
							if(board[0][0] == ' ' && botNeedsToMove) {
								board[0][0] = 'O';
								botNeedsToMove = false;
								//cout << "7\n";
							} else if(board[2][2] == ' ' && botNeedsToMove){
								board[2][2] = 'O';
								botNeedsToMove = false;
								//cout << "8\n";
							} else if(botNeedsToMove){
								botPath = 2;
								//cout << "9\n";
							}
						} else if(ogCornerCol == 2 && ogCornerRow == 0 && botNeedsToMove) {
							if(board[0][0] == ' ' && botNeedsToMove) {
								board[0][0] = 'O';
								botNeedsToMove = false;
								//cout << "10\n";
							} else if(board[2][2] == ' ' && botNeedsToMove){
								board[2][2] = 'O';
								botNeedsToMove = false;
								//cout << "11\n";
							} else if(botNeedsToMove) {
								botPath = 2;
								//cout << "12\n";
							}
						} else {
							botPath = 2;
							botNeedsToMove = false;
							//cout << "13\n";
						}
						/*if(botPath == 2 && botNeedsToMove) {
							randBotPath();
							botNeedsToMove = false;
						}*/
					}
				}
				if(movesMade == 2 && botNeedsToMove) {
					if(botPath == 1 && botNeedsToMove) {
						if(ogCornerCol == 0 && ogCornerRow == 0 && botNeedsToMove) {
							if(board[0][2] == ' ' && botNeedsToMove) {
								board[0][2] = 'O';
								botNeedsToMove = false;
								//cout << "1\n";
							} else if(board[2][0] == ' ' && botNeedsToMove){
								board[2][0] = 'O';
								botNeedsToMove = false;
								//cout << "2\n";
							} else if(botNeedsToMove) {
								botPath = 2;
								//cout << "3\n";
							}
						} else if(ogCornerCol == 2 && ogCornerRow == 2 && botNeedsToMove) {
							if(board[0][2] == ' ' && botNeedsToMove) {
								board[0][2] = 'O';
								botNeedsToMove = false;
								//cout << "4\n";
							} else if(board[2][0] == ' ' && botNeedsToMove){
								board[2][0] = 'O';
								botNeedsToMove = false;
								//cout << "5\n";
							} else {
								botPath = 2;
								//cout << "6\n";
							}
						} else if(ogCornerCol == 0 && ogCornerRow == 2 && botNeedsToMove) {
							if(board[0][0] == ' ' && botNeedsToMove) {
								board[0][0] = 'O';
								botNeedsToMove = false;
								//cout << "7\n";
							} else if(board[2][2] == ' ' && botNeedsToMove){
								board[2][2] = 'O';
								botNeedsToMove = false;
								//cout << "8\n";
							} else if(botNeedsToMove) {
								botPath = 2;
								//cout << "9\n";
							}
						} else if(ogCornerCol == 2 && ogCornerRow == 0 && botNeedsToMove) {
							if(board[0][0] == ' ' && botNeedsToMove) {
								board[0][0] = 'O';
								botNeedsToMove = false;
								//cout << "10\n";
							} else if(board[2][2] == ' ' && botNeedsToMove){
								board[2][2] = 'O';
								botNeedsToMove = false;
								//cout << "11\n";
							} else if(botNeedsToMove) {
								botPath = 2;
								//cout << "12\n";
							}
						} else if(botNeedsToMove) {
							botPath = 2;
							//cout << "13\n";
						}
						if(botPath == 2 && botNeedsToMove) {
							randBotPath();
							botNeedsToMove = false;
						}
					}
					if(botPath == 2 && botNeedsToMove) {
						randBotPath();
						botNeedsToMove = false;
					}
				}
				if(movesMade == 3 && botNeedsToMove) {
					if(botPath == 1 && botNeedsToMove) {
						if(board[1][1] == ' ' && botNeedsToMove) {
							board[1][1] = 'O';
							botNeedsToMove = false;
						} else if(botNeedsToMove) {
							botPath = 2;
						}
					}
					if(botPath == 2 && botNeedsToMove) {
						randBotPath();
						botNeedsToMove = false;
					}
				}
				if(movesMade == 4 && botNeedsToMove) {
					if(botPath == 1 && botNeedsToMove) {
						if(board[(ogCornerCol + 2) % 3][(ogCornerRow) % 3] == ' ') {
							board[(ogCornerCol + 2) % 3][ogCornerRow % 3] = 'O';
							botNeedsToMove = false;
						} else if(board[(ogCornerCol) % 3][(ogCornerRow + 2) % 3] == ' ') {
							board[(ogCornerCol)% 3][(ogCornerRow + 2) % 3] = 'O';
							botNeedsToMove = false;
						} else if(board[(ogCornerCol + 2) % 3][(ogCornerRow + 2) % 3] == ' '){
							board[(ogCornerCol + 2) % 3][(ogCornerRow + 2) % 3] = 'O';
							botNeedsToMove = false;
						} else {
							if(board[0][1] == ' ' && botNeedsToMove) {
								board[0][1] = 'O';
								botNeedsToMove = false;
							} else if(board[1][0] == ' ' && botNeedsToMove) {
								board[1][0] = 'O';
								botNeedsToMove = false;
							} else if(board[1][2] == ' ' && botNeedsToMove) {
								board[1][2] = 'O';
								botNeedsToMove = false;
							} else if(board[2][1] == ' ' && botNeedsToMove) {
								board[2][1] = 'O';
								botNeedsToMove = false;
							} else {
								botPath = 2;
							}
						}
					}
					if(botPath == 2 && botNeedsToMove) {
						randBotPath();
						botNeedsToMove = false;
					}
				}
			}
			if(botNeedsToMove) {
				randBotPath();
				botPath  = 2;
				botNeedsToMove = false;
			}
			whoseMove = 1;
		}
		printBoard();
		//cout << "\nMoves made: " << movesMade << "\n";
		if(checkWin('O')) {
			cout << "\nBetter luck next time!";
			return 0;
		}
		if(checkWin('X')) {
			cout << "\nCongratulations!";
			return 0;
		}
		if(checkTie()) {
			cout << "\nIt's a tie!";
			return 0;
		}
	}
}