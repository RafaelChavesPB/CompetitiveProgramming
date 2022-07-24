#include <bits/stdc++.h>
#define debug___(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl
#define debug__(a,b) cout<<(a)<<' '<<(b)<<endl
#define debug_(a) cout<<(a)<<endl
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<char, int>> v;
        vector<int> cont(256, 0);
        int n, m, b;
        char c;
        string line;
        cin >> n;
        getline(cin,line);
        while (n--)
        {
            getline(cin,line);
            c=line[0];
            b=stoi(line.substr(2),nullptr);
            v.push_back({c,b});
        }
        
        cin >> m;
        getline(cin,line);
        while (m--)
        {
            getline(cin, line);
            for (auto x : line)
                cont[x]++;
        }

        long long ans = 0;
        for(auto x:v){
            ans+=cont[x.first]*x.second;
            // debug__(cont[x.first],cont[x.first]*x.second);
        }
        cout<<fixed<<setprecision(2)<<ans/100.0<<'$'<<endl;
    }
}