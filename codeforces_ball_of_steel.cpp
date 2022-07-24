//Problema disponivel em: https://codeforces.com/problemset/problem/1450/B

#include <bits/stdc++.h>
#define pi pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pi> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i].F>>arr[i].S;
        bool flag = false;
        for(int i=0;i<n;i++){
            flag = true;
            for(int j=0;j<n;j++){
                if(abs(arr[i].F-arr[j].F)+abs(arr[i].S-arr[j].S)>k){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<1<<endl;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}