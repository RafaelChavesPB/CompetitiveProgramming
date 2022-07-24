#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<pair<bool, bitset<100>>> pd;

int compare(int pos)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        if (!pd[pos].second[i])
            sum += v[i];
    if (sum == pos)
        return sum;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        int m, n, p;
        v.clear();
        cin >> m;
        while (m--)
        {
            cin >> p >> n;
            while (n--)
                v.push_back(p);
        }
        
        pd = vector<pair<bool, bitset<100>>>(500*v.size());
        
        pd[1].first = true;
        for (int i = 0; i < v.size(); i++)
            for (int j = pd.size(); j > 0; j--)
            {
                int pos = v[i] * j;
                if (pos >= pd.size())
                    continue;
                if (pd[j].first)
                {
                    pd[pos].first =  true;
                    pd[pos].second = pd[j].second;
                    (pd[pos].second)[i] = true;
                }
            }
        
        int ans = 0;
        for (int pos = 0; pos < pd.size(); pos++)
        {
            if (pd[pos].first)
                ans = max(compare(pos), ans);
        }
        cout << "Case #" << T << ": " << ans << endl;
    }
    return 0;
}