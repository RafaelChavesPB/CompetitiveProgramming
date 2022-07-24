#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, l, r, op;
    cin >> n;
    vector<long long> prefix_u(n + 1, 0), prefix_v(n + 1, 0), stones(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        cin >> stones[i];
        prefix_v[i] = prefix_v[i - 1] + stones[i];
    }
    sort(stones.begin(), stones.end());
    for (long long i = 1; i <= n; i++)
        prefix_u[i] = prefix_u[i - 1] + stones[i];
    cin >> m;
    while (m--)
    {
        cin >> op >> l >> r;
        if(op == 1)
            cout<<prefix_v[r]-prefix_v[l-1]<<endl;
        else
            cout<<prefix_u[r]-prefix_u[l-1]<<endl;
    }
    return 0;
}