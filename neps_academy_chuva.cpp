#include <bits/stdc++.h>

using namespace std;
int main (){
    int n,atual,num,cont=0,ans=0;
    stack<int> pilha;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>num;
        while(!pilha.empty() and num>pilha.top()){
            cont=0;   
            atual=pilha.top();
            while(!pilha.empty() and atual==pilha.top()){
                pilha.pop();
                cont++;
            }
            if(!pilha.empty()){
              ans+=cont;  
            }
        }
        pilha.push(num);
    }

    // while(!pilha.empty()){
    //     cout<<pilha.top()<<' ';
    //     pilha.pop();
    // }
    
    cout<<ans<<endl;
}
