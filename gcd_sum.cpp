#include <bits/stdc++.h>
using namespace std;

long long  decompose(long long n){
    long long sum = 0;
    do{
        sum+=n%10;
        n/=10;
    }while(n>0);
    return sum;
}
int main(){
    int t ;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        while(__gcd(n,decompose(n))<2){
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}