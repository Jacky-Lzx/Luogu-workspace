#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int n;
    cin >> n;

    int a[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];

            if (i - 1 >= 0 && j <= i - 1) // the up one exists
            {
                if (j - 1 >= 0) // the up-left one exists
                {
                    a[i][j] += max(a[i-1][j], a[i-1][j-1]);
                    continue;
                }
                a[i][j] += a[i-1][j];
            }
            else if (j - 1 >= 0)
            {
                a[i][j] += a[i-1][j-1];
            }
        }
    }

    int temp = a[n-1][0];
    for (int i = 1; i < n; i++)
    {
        if (temp < a[n-1][i])
            temp = a[n-1][i];
    }
    cout << temp << endl;

}