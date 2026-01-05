#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

// In bảng Sudoku
void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            if (board[i][j] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Kiểm tra xem có thể đặt số num vào vị trí (row, col) không
bool isSafe(vector<vector<int>> &board, int row, int col, int num)
{
    // Kiểm tra hàng ngang
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num)
        {
            return false;
        }
    }

    // Kiểm tra hàng dọc
    for (int x = 0; x < N; x++)
    {
        if (board[x][col] == num)
        {
            return false;
        }
    }

    // Kiểm tra khối 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Giải Sudoku bằng thuật toán Backtracking
bool solveSudoku(vector<vector<int>> &board)
{
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Tìm ô trống đầu tiên
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
        {
            break;
        }
    }

    // Không còn ô trống, Sudoku đã được giải
    if (!isEmpty)
    {
        return true;
    }

    // Thử các số từ 1 đến 9
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            // Đệ quy để giải tiếp
            if (solveSudoku(board))
            {
                return true;
            }

            // Nếu không thành công, quay lui
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    // Bảng Sudoku mẫu (0 đại diện cho ô trống)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Bảng Sudoku ban đầu:" << endl;
    printBoard(board);
    cout << endl;

    if (solveSudoku(board))
    {
        cout << "Bảng Sudoku sau khi giải:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "Không có lời giải!" << endl;
    }

    return 0;
}