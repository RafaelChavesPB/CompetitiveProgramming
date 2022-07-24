#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,pos=0,id;
        string dir;
        vector<int> movs;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>dir;
            if(dir=="RIGHT"){
                movs.push_back(1);
                pos++;
            }else if(dir=="LEFT"){
                movs.push_back(-1);
                pos--;    
            }else{
                cin>>dir>>id;
                movs.push_back(movs[id-1]);
                pos+=movs[id-1];
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}