#include <bits/stdc++.h>

using namespace std;

vector<long long> fatorar(long long n){
    vector<long long> primos;
    vector<long long> crivo((int) sqrt(n)+1,1);
    vector<long long> fatores;

    for(long long i=2; i<=sqrt(n);i++){
        if(crivo[i]){
            primos.push_back(i);
            for(long long j=2*i;j<=sqrt(n);j+=i){
                crivo[j]=0;
            }
        }
    }


    for(auto x:primos){
        if(n%x==0){
            fatores.push_back(x);
            n/=x;
            while(n%x==0){
                fatores.back()*=x;
                n/=x;
            }
        }
    }
    fatores.push_back(n);

    return fatores;
}

long long  func(long long a, long long b, int pos, vector<long long> v){
    if(pos==v.size()){
        return max(a,b);
    }

    return min(func(a*v[pos],b/v[pos],pos+1,v),func(a,b,pos+1,v));
}

int main(){
    long long n;
    cin>>n;
    auto fatores=fatorar(n);
    auto a=func(1,n,0,fatores);
    cout<<a<<' '<<n/a<<endl;

    return 0;
}