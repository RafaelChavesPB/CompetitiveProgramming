#include <bits/stdc++.h>
using namespace std;

long long test(int n, vector<int> v, int it){
    long long acc = 0, carry = 0;
    int ini = 0, p = 0;
    for(int i=0;i<2;i++){
        do{
            acc += carry;
            if(v[p]>=0){
                carry+=v[p];
                v[p]=0;
            }else if(carry){
                int dim = min((long long)abs(v[p]),carry);
                carry -= dim;
                v[p] += dim;
            }
            p+=it;
            if(p<0){
                p+=n;
            }else if(p>=n){
                p%=n;
            }
        }while(p!=ini);
    }
    return acc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, acc = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        acc+=v[i];
    }
    int eq = acc/n;
    for(int i=0;i<n;i++){
        v[i]-=eq;
    }
    cout<<min(test(n,v,-1),test(n,v,1))<<endl;
    return 0;
}