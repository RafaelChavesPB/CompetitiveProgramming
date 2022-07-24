#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,temp;
    int n;
    stack<char> pilha;

    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin,temp);
        s+=temp;
    }
    bool ok=true;
    for(auto c: s){
        if(c=='{')
            pilha.push('{');
        else if(c=='}'){
            if(pilha.empty()){
                ok=false;
                break;
            }else{
                pilha.pop();
            }
        }
    }
    if(!ok or !pilha.empty()){
        cout<<'N'<<endl;
    }else{
        cout<<'S'<<endl;
    }
    return 0;
}