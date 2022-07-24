#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b, c;
    while (cin >> n >> m, n or m)
    {
        string ans = "NO CONFLICT";
        vector<int> bits(1000001);
        for(int t=0;t<n;t++)
        {
            cin >> a >> b;
            for (int i = a; i < b; i++)
            {
                if (bits[i])
                {
                    ans = "CONFLICT";
                }
                else
                {
                    bits[i] = true;
                }
            }
        }
        for(int t=0;t<m;t++)
        {
            cin >> a >> b >> c;
            while (a < 1000000)
            {
                for (int i = a; i < min(b, 1000000); i++)
                {
                    if (bits[i])
                    {
                        ans = "CONFLICT";
                    }
                    else
                    {
                        bits[i] = true;
                    }
                }
                a+=c;
                b+=c;
            }
        }
        cout << ans << endl;
    }
}