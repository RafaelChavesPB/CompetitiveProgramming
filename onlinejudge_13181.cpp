#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    while(cin>>in){
        vector<int> q;
        int acc=0;
        for(auto i:in){
            if(i=='X'){
                q.push_back(acc);
                acc=0;
            }
            else{
                acc++;
            }
        }
        q.push_back(acc);
        int ans=max(q.front()-1,q.back()-1);
        for(int i=1;i<q.size()-1;i++){
            ans=max(ans,(q[i]-1)/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}