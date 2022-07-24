#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, y, x, n, diff, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        for (int i = n - 1; i > 0; i--)
        {
            if ((y - x) % i == 0)
            {
                diff = (y - x) / i;
                break;
            }
        }
        p = y;
        while (p >= x)
        {
            cout << p << ' ';
            p -= diff;
            n--;
        }
        p = x - diff;
        while (p > 0 and n > 0)
        {
            cout << p << ' ';
            p -= diff;
            n--;
        }
        while (n > 0)
        {
            y += diff;
            n--;
            cout << y << ' ';
        }
        cout << endl;
    }
}