#include <iostream>
#include <iomanip>
using namespace std;
#define N 8

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void Inbanco(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col)
{
    return (row >= 0 && row < N && col >= 0 && col < N && board[row][col] == 0);
}
bool solveKTUtil(int board[N][N], int curr_x, int curr_y, int movei)
{
    if (movei == N * N)
    {
        return true;
    }
    for (int k = 0; k < 8; k++)
    {
        int next_x = curr_x + dx[k];
        int next_y = curr_y + dy[k];
        if (isSafe(board, next_x, next_y))
        {
            board[next_x][next_y] = movei;
            if (solveKTUtil(board, next_x, next_y, movei + 1))
            {
                return true;
            }
            else
            {
                board[next_x][next_y] = 0; // backtracking
            }
        }
    }
    return false;
}

int main()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    board[0][0] = 1;

    if (!solveKTUtil(board, 0, 0, 2))
    {
        cout << "Solution does not exist" << endl;
    }
    else
    {
        Inbanco(board);
    }
    return 0;
}
