//Problema disponivel em: https://codeforces.com/problemset/problem/1526/B
#include <bits/stdc++.h>
#define DEBUG 
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
#else
    #define bug(X) {;}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n;
        b = n%11;
        a = n/11 - 10*b;
        if(b*111+a*11== n and a>=0)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0;
}