#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m, temp, ans=0;
    vector<long long> can;
    cin>>n>>m;
    while(n--){
        cin>>temp;
        can.push_back(temp);
    }
    sort(can.begin(),can.end());
    int value;
    while(m--){
        cin>>value;
        ans+= (*lower_bound(can.begin(),can.end(),value))-value;
    }
    cout<<ans<<endl;

}