#include <bits/stdc++.h>

using namespace std;


int main(){
    priority_queue<int, vector<int>, greater<int>> fp;
    int c,n,chegada,t_atendimento, cont;
    cin>>c>>n;
    for(int i=0;i<c;i++,n--){
        cin>>chegada>>t_atendimento;
        fp.push(chegada+t_atendimento);
    }
    for(int i=0;i<n;i++){
        cin>>chegada>>t_atendimento;
        auto atual=fp.top();
        fp.pop();
        if(atual-chegada>20)
            cont++;
        fp.push(max(atual,chegada)+t_atendimento);
    }

    cout<<cont<<endl;
    return 0;
}
