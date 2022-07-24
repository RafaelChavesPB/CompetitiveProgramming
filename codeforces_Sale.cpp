#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,temp,ans=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin>>n>>m;
    while(n--){
        cin>>temp;
        pq.push(temp);
    }
    while(m--){
        if(pq.top()>=0){
            break;
        }
        ans-=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
    return 0;
}