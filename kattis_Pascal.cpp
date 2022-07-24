#include <bits/stdc++.h>

using namespace std;

vector<int> crivo(int tam){
    bool v[tam+1]={1,1};
    vector<int> primos;
    for (int i=2; i<tam; i++){
        if(!v[i]){
            primos.push_back(i);
            for(int j=2*i;j<=tam;j+=i){
                v[j]=1;
            }
        }
    }
    return primos;
}

int factor(int n,vector<int> v){
    for(auto x: v){
        if(n%x==0){
            return n - n/x;
        }
    }
    return n-1;
}
int main(){
    
    int n;

    cin>>n;

    auto v=crivo(100000);

    cout<<factor(n, v)<<endl;

}