#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> n(5),m(5);
    while(cin>>n[0]){
        string ans="Y";
        cin>>n[1]>>n[2]>>n[3]>>n[4];
        cin>>m[0]>>m[1]>>m[2]>>m[3]>>m[4];
        for(int i=0;i<5;i++){
            if(n[i]==m[i])
                ans="N";
        }
        cout<<ans<<endl;
    }
}



