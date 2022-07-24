#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,ans=0;
    string s;
    deque<char> dq;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        dq.assign(s.begin(),s.end());
        s.clear();
        while(!dq.empty()){
            if(!s.empty() and dq.front()==s.back()){
                ans++;
            }else{
                s.push_back(dq.front());
            }
            dq.pop_front();
        }
    }
    cout<<ans<<endl;
    return 0;
}
