#include<iostream>

using namespace std;

int main()
{
    int horseX, horseY;
    int finalX, finalY;

    cin >> finalX >> finalY >> horseX >> horseY;

    if (horseX == 0 && horseY == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (horseX == finalX && horseY == finalY)
    {
        cout << 0 << endl;
        return 0;
    }

    finalX++;
    finalY++;

    long long board[finalX][finalY];
    for (int i = 0; i < finalX; i++)
    {
        for (int j = 0; j < finalY; j++)
        {
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;

    board[horseX][horseY] = -1;

    int step[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {1, 2}, {-1, 2}, {-2, 1}, {2, -1}, {2, 1}};

    for (int i = 0; i < 8; i++)
    {
        int x = horseX + step[i][0];
        int y = horseY + step[i][1];

        if (x >= 0 && x < finalX && y >= 0 && y < finalY)
        {
            board[x][y] = -1;
        }
    }

    for (int i = 1; i < finalY; i++)
    {
        if (board[0][i] != -1)
            board[0][i] = (board[0][i-1] == -1 ? 0 : board[0][i - 1]);
    }
    for (int i = 1; i < finalX; i++)
    {
        if (board[i][0] != -1)
            board[i][0] = (board[i-1][0] == -1 ? 0 : board[i-1][0]);
    }

    for (int i = 1; i < finalX; i++)
    {
        for (int j = 1; j < finalY; j++)
        {
            if (board[i][j] == -1)
                continue;


            board[i][j] = board[i-1][j] + board[i][j-1];

            if (board[i][j - 1] == -1)
                board[i][j]++;
            if (board[i-1][j] == -1)
                board[i][j]++;
        }
    }

    cout << board[finalX-1][finalY-1] << endl;

    // for (int i = 0; i < finalX; i++)
    // {
    //     for (int j = 0; j < finalY; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

}