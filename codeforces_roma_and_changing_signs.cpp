#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,k,a,ans=0;
    cin>>n>>k;
    while(n--){
        cin>>a;
        pq.push(a);
    }
    while(k--){
        a =  pq.top();
        pq.pop();
        pq.push(-a);
    }
    while(pq.size()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;

    return 0;
}