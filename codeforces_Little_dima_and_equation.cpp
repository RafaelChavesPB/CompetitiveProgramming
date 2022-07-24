#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

int a,b,c;
int sliceAndSum(long long num){
    int acc=0;
    while(num){
        acc+=num%10;
        num/=10;
    }
    return acc;
}
void solve(){ 
    for(int i=1;i<=81;i++){
        long long x = b*pow(i,a)+c;
        if(sliceAndSum(x)==i and x < 1e+9)
            ans.push_back(x);
    }
    
}
int main(){
    cin>>a>>b>>c;
    solve();
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto x: ans){
        cout<<x<<' ';
    }
    cout<<endl;
}