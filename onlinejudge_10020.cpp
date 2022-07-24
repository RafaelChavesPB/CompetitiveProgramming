#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        bool flag = true;
        bool curValid = false;
        int m, curMax = 0, reqMin = 0;
        pair<int, int> curBest;
        vector<pair<int, int>> v, ans;
        cin >> m;
        while (cin >> a >> b, a or b)
            v.push_back({a, b});
        sort(v.begin(), v.end());
        for (auto p : v)
        {
            if (p.first <= reqMin)
            {
                if (p.second >= curBest.second)
                {
                    curValid = true;
                    curBest = p;
                }
            }
            else
            {
                if(curValid){
                    curValid=false;
                    reqMin = curBest.second;
                    ans.push_back(curBest);
                    if(reqMin>=m){
                        break;
                    }
                }
                if(p.first<=reqMin){
                    if(p.second>=curBest.second){
                        curValid=true;
                        curBest=p;
                    }
                }else{
                    flag=false;
                    break;
                }
            }
        }
        if(curValid){
            ans.push_back(curBest);
            reqMin = curBest.second;
        }
        if (flag and reqMin>=m)
        {
            cout << ans.size() << endl;
            for (auto x : ans)
            {
                cout << x.first << ' ' << x.second << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
        if (t)
            cout << endl;
    }
}