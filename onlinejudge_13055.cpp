#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string op, name;
    stack<string> pilha;
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="Sleep"){
            cin>>name;
            pilha.push(name);
        }else if(op=="Test"){
            if(pilha.size())
                cout<<pilha.top()<<endl;
            else
                cout<<"Not in a dream"<<endl;
        }else{
            if(pilha.size())
                pilha.pop();
        }
    }
    return 0;
}