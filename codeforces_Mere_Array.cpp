#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a;
    cin >> t;
    while (t--)
    {
        int menor=INT_MAX;
        vector<pair<int,int>> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            menor=min(menor,a);
            v.push_back(make_pair(a,i));
        }
        sort(v.begin(), v.end());
        string ans="YES";
        for(int i=0;i<n;i++){
            if(v[i].second!=i){
                if(menor!=__gcd(menor,v[i].first)){
                    ans="NO";
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}