#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans=0;
    char op,equal;
    string out;
    while(cin>>a>>op>>b>>equal>>out){
        if(out!="?"){
            int resp=stoi(out);
            if(op=='-'){
                b*=-1;
            }
            if(a+b==resp){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}