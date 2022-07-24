#include <bits/stdc++.h>

using namespace std;

vector<int> ma[100005];

int main(){
    int n,m,t,ini,fim;
    cin>>n>>m;
    while(m--){
        cin>>t>>ini>>fim;
        if(t){
            ma[ini].push_back(fim);
            ma[fim].push_back(ini);
        }else{
            if(find(ma[ini].begin(),ma[ini].end(),fim)!=ma[ini].end())
                cout<<1<<endl;
            else
            {
                cout<<0<<endl;
            }
            
        }
    }
    return 0;
}