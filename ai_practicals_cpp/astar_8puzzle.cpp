#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int g = 0;

void printBoard(vector<int> board)
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
            cout << endl;

        if(board[i] == -1)
            cout << "_ ";
        else
            cout << board[i] << " ";
    }

    cout << endl;
}

bool solvable(vector<int> start)
{
    int inv = 0;

    for(int i=0;i<9;i++)
    {
        if(start[i] == -1)
            continue;

        for(int j=i+1;j<9;j++)
        {
            if(start[j] == -1)
                continue;

            if(start[i] > start[j])
                inv++;
        }
    }

    return (inv % 2 == 0);
}

int heuristic(vector<int> start, vector<int> goal)
{
    int h = 0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(start[i] == goal[j] && start[i] != -1)
            {
                h += abs(i-j)/3 + abs(i-j)%3;
            }
        }
    }

    return h + g;
}

void moveLeft(vector<int> &board, int pos)
{
    swap(board[pos], board[pos-1]);
}

void moveRight(vector<int> &board, int pos)
{
    swap(board[pos], board[pos+1]);
}

void moveUp(vector<int> &board, int pos)
{
    swap(board[pos], board[pos-3]);
}

void moveDown(vector<int> &board, int pos)
{
    swap(board[pos], board[pos+3]);
}

void moveTile(vector<int> &start, vector<int> goal)
{
    int empty = 0;

    for(int i=0;i<9;i++)
    {
        if(start[i] == -1)
        {
            empty = i;
            break;
        }
    }

    int row = empty / 3;
    int col = empty % 3;

    vector<int> t1 = start;
    vector<int> t2 = start;
    vector<int> t3 = start;
    vector<int> t4 = start;

    int f1 = 100;
    int f2 = 100;
    int f3 = 100;
    int f4 = 100;

    if(col-1 >= 0)
    {
        moveLeft(t1, empty);
        f1 = heuristic(t1, goal);
    }

    if(col+1 < 3)
    {
        moveRight(t2, empty);
        f2 = heuristic(t2, goal);
    }

    if(row-1 >= 0)
    {
        moveUp(t3, empty);
        f3 = heuristic(t3, goal);
    }

    if(row+1 < 3)
    {
        moveDown(t4, empty);
        f4 = heuristic(t4, goal);
    }

    int minValue = min(f1, min(f2, min(f3, f4)));

    if(minValue == f1)
        moveLeft(start, empty);

    else if(minValue == f2)
        moveRight(start, empty);

    else if(minValue == f3)
        moveUp(start, empty);

    else if(minValue == f4)
        moveDown(start, empty);
}

void solveEight(vector<int> &start, vector<int> goal)
{
    g++;

    moveTile(start, goal);

    printBoard(start);

    int f = heuristic(start, goal);

    if(f == g)
    {
        cout << "\nSolved in " << g << " moves";
        return;
    }

    solveEight(start, goal);
}

int main()
{
    vector<int> start(9);
    vector<int> goal(9);

    cout << "Enter Start State (-1 for empty):\n";

    for(int i=0;i<9;i++)
        cin >> start[i];

    cout << "Enter Goal State:\n";

    for(int i=0;i<9;i++)
        cin >> goal[i];

    printBoard(start);

    if(solvable(start))
    {
        solveEight(start, goal);
    }
    else
    {
        cout << "Not Solvable";
    }

    return 0;
}
