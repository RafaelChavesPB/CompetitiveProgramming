#include <bits/stdc++.h>
using namespace std;

array<int,3> val;
array<array<int,3>,3> lig;

int solve(){
    int zeros=0;
    while(zeros<2){
        pair<int,int> mx(0,0);
        for(int i=0;i<=2;i++)
            mx = max(mx,make_pair(val[i],i));
        for(int i=0;i<=2;i++){
            if(mx.second != i and val[mx.second] and val[i]){
                if(--val[i]==0)
                    zeros++;
                if(--val[mx.second]==0)
                    zeros++;
                lig[mx.second][i]++;
                lig[i][mx.second]++;
            }   
        }
    }
    return zeros;
}
int main(){
    pair<int, int> first(0,0);
    for(int i=0;i<3;i++)
        cin>>val[i];
    
    if(solve()!=3){
        cout<<"Impossible"<<endl;
    }else{
        cout<<lig[0][1]<<' '<<lig[1][2]<<' '<<lig[0][2]<<endl;
    }
    return 0;
}