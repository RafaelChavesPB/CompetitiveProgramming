#include <bits/stdc++.h>
#define _debug(x) cout << x << endl
#define __debug(x, y) cout << x << ' ' << y << endl
using namespace std;
int main()
{
    int n, m;
    double w, x;
    while (cin >> n >> m >> w, n and m)
    {
        string ans = "YES";
        vector<double> v1, v2;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v1.push_back(x);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            v2.push_back(x);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        w /= 2;
        if (w < v1[0] or v1[n - 1] + w < 75 or w < v2[0] or v2[m - 1] + w < 100){
            ans="NO";
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v1[i] + 2*w < v1[i + 1])
                ans = "NO";
        }
        for (int i = 0; i < m - 1; i++)
        {
            if (v2[i] + 2*w < v2[i + 1])
                ans = "NO";
        }

        cout << ans << endl;
    }
}