//
// Created by lzx on 2020-3-2.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, R;
    char code[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    cin >> n >> R;
    int origin = n;

    string a;
    while(n != 0)
    {
        int divide = n / R;
        int mod = n % R;
        if (mod < 0)
        {
            mod = mod + (R < 0 ? -R : R);
            divide = divide + (divide >= 0 ? 1 : -1);
        }

        a.insert(a.begin(), code[mod]);
        n = divide;
    }

    cout << origin << '=' << a << "(base" << R << ')' << endl;
}