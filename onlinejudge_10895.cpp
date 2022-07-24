#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    while(cin>>n>>m){
        vector<vector<int>> a(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            vector<int> p(m);
            vector<int> num(m);
            cin>>t;
            for(int k=0;k<t;k++){
                cin>>p[k];
            }
            for(int k=0;k<t;k++){
                cin>>num[k];
                a[i][p[k]]=num[k];
            }
        }
        cout<<m<<' '<<n<<endl;
        for(int i=1;i<=m;i++){
            vector<int> p;
            vector<int> num;
            for(int j=1;j<=n;j++){
                if(a[j][i]){
                    p.push_back(j);
                    num.push_back(a[j][i]);
                }
            }
            cout<<p.size();
            for(auto x: p)
                cout<<' '<<x;
            cout<<endl;
            bool first=true;
            for(auto x: num)
            {
                if(!first)
                    cout<<' ';
                else 
                    first=false;
                cout<<x;

            }
            cout<<endl;
        }
    }
    return 0;
}