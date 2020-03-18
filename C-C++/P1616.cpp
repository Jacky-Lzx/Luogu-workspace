
// AC
#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int T, M;
    cin >> T >> M;

    int times[M+1];
    int money[M+1];

    for (int i = 1; i < M+1; i++)
    {
        cin >> times[i] >> money[i];
    }


    int maps[T+1];
    for (int i = 0; i < T+1; i++)
    {
        maps[i] = 0;
    }

    for (int i = 1; i < M+1; i++)
    {
        for (int j = times[i]; j < T+1; j++)
        {
            maps[j] = max(maps[j], maps[j - times[i]] + money[i]);
        }
    }

    cout << maps[T] << endl;
}