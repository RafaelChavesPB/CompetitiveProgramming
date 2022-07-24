#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 0, min_o = INT_MAX, min_c = INT_MAX;
        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            min_c = min(v[i].first, min_c);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second;
            min_o = min(v[i].second, min_o); 
        }
        for(auto p : v){
            ans += max( p.first - min_c, p.second - min_o);
        }
        cout<<ans<<endl;
    }
    return 0;
}