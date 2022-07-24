#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    int cases,n,a,b;
    stack<int> pilha;
    cin>>cases;
    while(cases--){
        a=0,b=0;
        cin>>n>>s;
        for(auto c: s){
            if(c==')'){
                if(pilha.empty()){
                    b++;
                }else{
                    pilha.pop();
                }
            }else{
                pilha.push(1);
            }
        }
        if(!pilha.empty()){
            pilha.pop();
        }
        cout<<b<<endl;
    }

    return 0;
}