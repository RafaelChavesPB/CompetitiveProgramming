//Problema disponível em: https://codeforces.com/problemset/problem/1506/C
#include<bits/stdc++.h>
using namespace std;
int tam(string &a, string &b){
    for(int i = a.size();i>0;i--){
        for(int j=0;j+i<=a.size();j++){
            if(b.find(a.substr(j,i))!=string::npos){
                return i;
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string a, b;
        string temp;
        cin>>a>>b;
        if(a.size()>b.size()){
            temp = a;
            a = b;
            b = temp;
        }
        cout<<a.size()+b.size()-2*tam(a,b)<<endl;
    }
    return 0;
}