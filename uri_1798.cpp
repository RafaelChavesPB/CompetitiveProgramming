#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> mochila;
vector<int> pd;
int rec(int resto)
{
    if (resto==0)
        return pd[resto]=0;
    if (pd[resto] != -1)
        return pd[resto];
    pd[resto]=0;
    for (auto p : mochila)
        if (resto >= p.first)
            pd[resto] = max(pd[resto], rec(resto - p.first) + p.second);

    return pd[resto];
}

int main()
{
    int a, b, n, t;
    cin >> n >> t;
    pd.assign(t+1,-1);
    while (n--)
    {
        cin >> a >> b;
        mochila.push_back(make_pair(a, b));
    }
    cout << rec(t) << endl;
    return 0;
}