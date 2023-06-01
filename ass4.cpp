#include <bits/stdc++.h>
using namespace std;

void printsol(vector<vector<int>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool issafe(vector<vector<int>>& board, int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 and j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 and i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solvenqutil(vector<vector<int>>& board, int col, int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (issafe(board, i, col, n))
        {
            board[i][col] = 1;
            if (solvenqutil(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solvenq()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solvenqutil(board, 0, n) == false){
        cout<<"no sol"<<endl;
        return false;
    }
    printsol(board, n);
}



int main()
{
    solvenq();
}