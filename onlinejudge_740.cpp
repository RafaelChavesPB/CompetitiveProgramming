#include <bits/stdc++.h>
using namespace std;
int decode(string c){
    int acc=0;
    for(int i=0;i<5;i++){
        if(c[i]=='1'){
            acc+=1<<5-(i+1);
        }
    }
    return acc;
}
int main(){
    string table[2],seq;
    getline(cin,table[0]);
    getline(cin,table[1]);
    while(cin>>seq){
        int mode=0;
        // string ans;
        for(int i=0;i<seq.size();i+=5){
            string c(seq.begin()+i,seq.begin()+i+5);
            if(c=="11011")
                mode=0;
            else if(c=="11111")
                mode=1;
            else{
                // cout<<c<<' '<<decode(c)<<endl;
                cout<<table[mode][decode(c)];
            }
        }
        cout<<endl;
        // cout<<ans<<endl;
    }
    return 0;
}