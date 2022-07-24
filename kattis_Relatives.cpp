#include <bits/stdc++.h>

using namespace std;

vector<int> crivo(int tam){
    bool v[tam+1]={1,1};
    vector<int> primos;
    for(int i=2;i<tam;i++){
        if(!v[i]){
            primos.push_back(i);
            for(int j=2*i;j<=tam;j+=i){
                v[j]=1;
            }
        }
    }
    return primos;
}

int totient(long long n, vector<int> primos){
    double ans=n;
    for(auto x: primos){
        if(n%x==0){
            while(n%x==0){
                n/=x;
            }
            ans*=(1- (1.0/x));
        }
    }

    if(n>1)
        ans*=(1- (1.0/n));

    return (int)ans;
}
int main(){
int n;
auto v =crivo(40000);
while(cin>>n and n){
    cout<<totient(n,v)<<endl;
}
    
}