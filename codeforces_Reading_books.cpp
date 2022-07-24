#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, t, a, b;
    vector<int> v01, v10, v11;
    deque<pair<int, int>> sa, sb;
    cin >> n >> k;
    while (n--)
    {
        cin >> t >> a >> b;
        if (a and b)
        {
            v11.push_back(t);
        }
        else if (a and !b)
        {
            v10.push_back(t);
        }
        else if (!a and b)
        {
            v01.push_back(t);
        }
    }
    sort(v01.begin(), v01.end(), greater<int>());
    sort(v10.begin(), v10.end(), greater<int>());
    sort(v11.begin(), v11.end(), greater<int>());
    int dif = max(k - v01.size(), k - v10.size());
    if (dif > 0)
    {
        if (v11.size() >= dif)
        {
            while (dif--)
            {
                sa.push_back(make_pair(v11.back(), 1));
                sb.push_back(make_pair(v11.back(), 1));
                v11.pop_back();
            }
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = sa.size(); i < k; i++)
    {
        sa.push_back(make_pair(v10.back(), 0));
        v10.pop_back();
    }
    for (int i = sb.size(); i < k; i++)
    {
        sb.push_back(make_pair(v01.back(), 0));
        v01.pop_back();
    }
    while (!v11.empty())
    {
        if (sa.back().second or sb.back().second)
        {
            break;
        }
        if (v11.back() < sa.back().first + sb.back().first)
        {
            sa.pop_back();
            sb.pop_back();
            sa.push_front(make_pair(v11.back(), 1));
            sb.push_front(make_pair(v11.back(), 1));
            v11.pop_back();
        }
        else
        {
            break;
        }
    }
    int ans=0;
    for (auto x : sa )
    {
        ans+=x.first;   
    }
    for(auto x : sb )
    {
        if(x.second!=1)
            ans += x.first;
    }
    cout<<ans<<endl;
    return 0;
} 