#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<char> pilha;
    string s;
    int t;
    cin>>t;
    while(t--){
        bool ok=true;
        cin>>s;
        for(auto i: s){
            if(i=='{' or i=='[' or i=='('){
                pilha.push(i);
            }else{
                if(!pilha.empty() and ((i=='}' and pilha.top()=='{') or (i==']' and pilha.top()=='[') or (i==')' and pilha.top()=='('))){
                    pilha.pop();
                }else{
                    ok=false;
                    break;
                }
            }
        }
        if(!pilha.empty() or !ok){
            cout<<'N'<<endl;
            while(!pilha.empty()){
                pilha.pop();
            }
        }else{
            cout<<'S'<<endl;
        }
    }
    return 0;
}