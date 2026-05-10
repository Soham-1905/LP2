#include <iostream>

using namespace std;

int board[10][10];

bool isSafe(int row, int col, int n)
{
    for(int i=0; i<col; i++)
    {
        if(board[row][i] == 1)
            return false;
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    for(int i=row, j=col; i<n && j>=0; i++, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int col, int n)
{
    if(col >= n)
        return true;

    for(int i=0; i<n; i++)
    {
        if(isSafe(i, col, n))
        {
            board[i][col] = 1;

            if(solve(col+1, n))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    if(solve(0, n))
    {
        cout << "Solution:\n";

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << "_ ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No Solution";
    }

    return 0;
}
