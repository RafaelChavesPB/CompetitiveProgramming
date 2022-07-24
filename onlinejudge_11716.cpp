#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s,out;
        getline(cin,s);
        int n = sqrt(s.size());
        if(n*n==s.size()){
            vector<vector<char>> m(n,vector<char>(n));
            for(int i=0;i<s.size();i++){
                m[i/n][i%n]=s[i];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    out+=m[j][i];
                }
            }
            out+='\n';
            cout<<out;
        }else{
            cout<<"INVALID"<<endl;
        }
    }
    return 0;
}