#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        vector<vector<int>> f(3);
        vector<int> p(10001);
        for(int j=0;j<3;j++){
            int s,a;
            cin>>s;
            while(s--){
                cin>>a;
                p[a]++;
                f[j].push_back(a);
            }
            sort(f[j].begin(),f[j].end());
        }
        pair<int,int> ans(0,0);
        vector<vector<int>>cont(3);
        for(int j=0;j<3;j++){
            for(auto k:f[j]){
                if(p[k]==1)
                    cont[j].push_back(k);
            }
            ans =  max(make_pair((int)cont[j].size(),j),ans);
        }
        cout<<"Case #"<<i<<":\n";
        for(int j=0;j<3;j++){
           if(cont[j].size()==ans.first){
                cout<<j+1<<' '<<cont[j].size();
                for(auto k:cont[j]){
                    cout<<' '<<k;
                }
                cout<<endl;
           } 
        }
    }
    return 0;
}