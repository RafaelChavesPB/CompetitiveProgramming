#include <bits/stdc++.h>

using namespace std;

int main(){
    int p,n;
    deque<pair<int,int>> v;
    cin>>p>>n;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(0,0));
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    while(n--){
        if(v.front().first>=p){
            cout<<"NO"<<endl;
            return 0;
        }
        p+=v.front().second;
        v.pop_front();
    }
    cout<<"YES"<<endl;
    return 0;
}