#include <iostream>
using namespace std;
#include "Tic-Tac.h"

#ifndef TICTAC_CPP
#define TICTAC_CPP

char board[3][3];

int ticTacToe()
{
    char currentPlayer = 'X';
    int row, col;
    initializeBoard();
    while (true)
    {
        displayBoard();
        cout << "Player" << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (placeMark(row, col, currentPlayer))
        {
            if (checkWin(currentPlayer))
            {
                displayBoard();
                cout << "Player" << currentPlayer << " wins!" << endl;
                break;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "It's Draw!" << endl;
                break;
            }
            else
            {
                switchPlayer(currentPlayer);
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
    return 0;
}

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard()
{
    cout << " 0 1 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << "/";
        }
        cout << '\n';
        if (i < 2)
            cout << " -----" << endl;
    }
}

bool placeMark(int row, int col, char mark)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = mark;
        return true;
    }
    return false;
}

bool checkWin(char mark)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == mark && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }

        if (board[0][i] == mark && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer)
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

#endif // TICTAC_CPP