#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    string s;
    cin>>n>>t>>s;
    while(t--){
        bool troca=false;
        for(int i=1;i<n;i++){
            if(troca)
                troca=false;
            else 
                if(s[i-1]=='B' and s[i]=='G'){
                    swap(s[i-1],s[i]);
                    troca=true;
                }
        }
    }
    cout<<s<<endl;
    return 0;
}