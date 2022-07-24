#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,d;
    string s;
    stack<char> pilha;
    while(cin>>n>>d, n or d){
        cin>>s;
        for(auto i:s){
            while(d and !pilha.empty() and pilha.top()<i){
                pilha.pop();
                d--;
            }
            pilha.push(i);
        }
        while(d--){
            pilha.pop();
        }
        s.clear();
        while(!pilha.empty()){
            s+=pilha.top();
            pilha.pop();
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }


    return 0;
}