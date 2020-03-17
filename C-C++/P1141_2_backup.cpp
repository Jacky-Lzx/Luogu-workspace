#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct position
{
    int x;
    int y;
}position;


int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    int map[n][n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < n; j++)
            map[i][j] = (temp.at(j) == '1' ? 1 : 0);
    }

    int countMap[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            countMap[i][j] = -1;


    int posX[4] = {0, 0, -1, 1};
    int posY[4] = {-1, 1, 0, 0};


    int flag[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            flag[i][j] = 0;

    int code = 0;
    vector<int> codeMap;
    codeMap.push_back(0);

    for(int i = 0; i < m; i++)
    {
        code++;

        position origin;
        cin >> origin.x;
        cin >> origin.y;
        origin.x--;
        origin.y--;

        /*if (countMap[origin.x][origin.y] != -1)
        {
            cout << countMap[origin.x][origin.y] << endl;
            continue;
        }*/
        if (flag[origin.x][origin.y] != 0)
        {
            cout << codeMap.at(flag[origin.x][origin.y]) << endl;
            continue;
        }


        int count = 1;
        vector<position> queue;
        
        queue.push_back(origin);



        while (!queue.empty())
        {
            position pos = queue.front();
            queue.erase(queue.begin());

            flag[pos.x][pos.y] = code;
            int num = map[pos.x][pos.y];

            for (int k = 0; k < 4; k++)
            {
                position newPos = (position){pos.x + posX[k], pos.y + posY[k]};
                if (newPos.x >= 0 && newPos.x < n && newPos.y >= 0 && newPos.y < n)
                {
                    if (num != map[newPos.x][newPos.y])
                    {
                        if (flag[newPos.x][newPos.y] == 0)
                        {
                            count++;
                            flag[newPos.x][newPos.y] = code;
                            queue.push_back(newPos);
                        }
                    }
                }
            }
        }


//        for (int j = 0; j < n; j++)
//            for (int k = 0; k < n; k++)
//                if (flag[j][k] == code)
//                    countMap[j][k] = count;
        codeMap.push_back(count);
        
        cout << count << endl;
    }


}