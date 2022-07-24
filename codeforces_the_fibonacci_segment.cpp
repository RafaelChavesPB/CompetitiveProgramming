#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, aux = 0, temp;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i < 2 or v[i] == v[i - 1] + v[i - 2])
            aux++;
        else
            aux = 2;
        ans = max(aux, ans);
    }
    cout << ans << endl;
}