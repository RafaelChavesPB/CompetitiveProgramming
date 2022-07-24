//Problema disponivel em: https://codeforces.com/problemset/problem/1350/B
#include <bits/stdc++.h>
#define DEBUG 
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
#else
    #define bug(X) {;}
#endif

using namespace std;

int arr[100001];
int mem[100001];

int rec(int num, int n){
    if(mem[num]!=-1){
        return mem[num];
    }
    int value = 0;
    for(int i=2*num; i<=n; i+=num){
        if(arr[num]<arr[i]){
            value = max(rec(i,n), value);
        }
    }
    return mem[num] = value + 1 ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    bug(t);
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mem[i]=-1;
        }
        int ans = 1;
        for(int i=1;i<=sqrt(n);i++){
            if(mem[i]==-1)
                ans = max(ans,rec(i,n));
        }
        cout<<ans<<endl;
    }
}