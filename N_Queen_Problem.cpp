#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
    return true;
}
bool solveNQueen(vector<vector<int>> &board, int col, int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            if (solveNQueen(board, col + 1, n))
                return true;
            board[i][col] = 0; // backtrack
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueen(board, 0, n))
    {
        cout << "Solution:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }
    cout << "This program is executed by Sahil Singh (Roll No: 2400320100951)" << endl;
    return 0;
}