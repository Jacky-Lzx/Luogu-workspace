
// AC   but the code is so ugly
#include <iostream>

using namespace std;

int R, C;
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int maps[101][101];
int counts[101][101];

int DFS(int r, int c)
{
    if (counts[r][c] >= 0)
        return counts[r][c];

    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        int x = r + direction[i][0];
        int y = c + direction[i][1];

        if (x >= 0 && x < R && y >= 0 && y < R)
        {
            if (maps[x][y] < maps[r][c])
            {
                int num;
                if (counts[x][y] == -1)
                    counts[x][y] = DFS(x, y);
                num = counts[x][y];

                max = (max >= num ? max : num);
            }
        }
    }
    counts[r][c] = max + 1;
    return max + 1;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            counts[i][j] = -1;
    }


    // important: every point has to be passed as the original point
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            DFS(i, j);
    }

    int longest = -1;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (longest < counts[i][j])
                longest = counts[i][j];
        }
    }

    cout << longest << endl;
}