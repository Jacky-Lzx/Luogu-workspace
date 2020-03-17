#include <iostream>

using namespace std;

// @link: https://www.luogu.com.cn/problemnew/solution/P1226
// the first way of quick power
/*  int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    int ans = 1;

    while(m != 0)
    {
        if (m & 1)
            ans *= n;

        m = m >> 1;
        n *= n;
    }
    cout << ans << endl;
} */

// The second way
/*
int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    int base = n;
    int ans = 1;
    while(m != 0)
    {
        if (m & 1) //m is odd
            ans *= base;

        base *= base;
        m = m >> 1;
    }
    cout << ans;
}*/


 int main()
{
    unsigned long long n, m, b;
    cin >> n;
    cin >> m;
    cin >> b;

    unsigned long long mOrigin = m;
    unsigned long long ans = 1;
    unsigned long long base = n;

    while(m != 0)
    {
        if (m & 1)
        {
            ans *= base;
            ans %= b;

        }

        m = m >> 1;
        base *= base;
        base %= b;
    }

    if (mOrigin == 0 && b == 1) ans = 0;
    cout << n << "^" << mOrigin << " mod " << b << "=" << ans << endl;
}
