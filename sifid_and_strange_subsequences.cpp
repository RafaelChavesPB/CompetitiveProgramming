#include <bits/stdc++.h>
#define N 100001
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int arr[N]={0};
    int t;
    cin>>t;
    while(t--){
        int n, a, p=0;
        int menor = INT_MAX;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>0){
                menor = min(menor,a);
            }else{
                arr[p++]=a;
            }
        }
        arr[p++]=menor;
        sort(arr,arr+p);
        int diff = INT_MAX;
        for(int i=1;i<p;i++)
            diff = min(arr[i]-arr[i-1],diff);
        if(diff<arr[p-1] or menor==INT_MAX){
            p--;
        }
        cout<<p<<endl;
    }
}