#include <bits/stdc++.h>

using namespace std;



int main(){
    long r, q_gas, q_baloes;
    double pi=3.1415,v_balao;
    
    cin>>r>>q_gas;
    v_balao=(pow(r,3)*4*pi/3);
    q_baloes=q_gas/v_balao;
    cout<<q_baloes<<"\n";
    return 0;
}
