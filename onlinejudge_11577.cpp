#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string in;
    cin >> t;
    getline(cin,in);
    while (t--)
    {
        int maior = 0;
        vector<int> v(26, 0);
        getline(cin,in);
        for (auto c : in)
        {
            if (c >= 'a' and c <= 'z')
            {
                maior = max(++v[c - 'a'], maior);
            }
            else if (c >= 'A' and c <= 'Z')
            {
                maior = max(++v[c - 'A'], maior);
            }
        }
        string ans;
        for(int i=0;i<26;i++){
            if(v[i]==maior)
                ans+=('a'+i);
        }
        cout<<ans<<endl;
    }
    return 0;
}