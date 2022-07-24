#include <bits/stdc++.h>
using namespace std;

int rec(int i, long long bm, int answer){
    if(i<0){
       int positivos = __builtin_popcount(bm);
       return positivos == answer;  
    }
    return rec( i-1, bm,answer) + rec(i-1,bm | 1 << i, answer); 
}

int main(){
    string a,b;
    int positivos=0;
    int interrogacoes=0;
    cin>>a>>b;
    for(auto c: a)
        positivos += (c == '+');
    for(auto c: b){
        positivos -= (c == '+');
        interrogacoes += (c == '?');
    }
    cout<<setprecision(10)<<fixed<<rec(interrogacoes-1,0,positivos)/double(1<<interrogacoes)<<endl;
    
}