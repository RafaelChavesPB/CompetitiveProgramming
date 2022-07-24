#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b;
    string s;
    int last = INT_MAX;
    cin >> n;
    vector<string> best(n);
    for(int i=0;i<n;i++){
        cin>>best[i];
    }
    cin >> m;
    while (m--){
        cin >> a;
        a--;
        if(best[a]!="?"){
            cout << best[a] << endl;
        }else{
            string ans;
            int left=-200, right=200;
            for(int i=0;i<a;i++)
                if(best[i]!="?")
                    left=i;
            for(int i=n-1;i>a;i--)
                if(best[i]!="?")
                    right=i;
            int dfl=a-left;
            int dfr=right-a;
            if(dfl<dfr){
                while(dfl--)
                    ans+="right of ";
                ans+=best[left];
            }else if(dfl>dfr){
                while(dfr--)
                    ans+="left of ";
                ans+=best[right];
            }else{
                ans="middle of "+best[left]+" and "+best[right];
            }
            cout<<ans<<endl;
        } 
    }
    return 0;
}