#ifndef TICTAC_H
#define TICTAC_H

int ticTacToe();
extern char board[3][3];
void initializeBoard();
void displayBoard();
bool placeMark(int row, int col, char mark);
bool checkWin(char mark);
bool checkDraw();
void switchPlayer(char &currentPlayer);

#endif // TICTAC_H