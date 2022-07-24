#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
long long n;
cin>>t;
    while(t--){
        cin>>n;
        long long delta = sqrt(1+8*n);
        cout<<(-1+delta)/2<<endl;
    }

}