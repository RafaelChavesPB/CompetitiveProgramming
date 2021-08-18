//Problema disponivel em: https://codeforces.com/problemset/problem/1547/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int k,m,n;
        cin>>k>>n>>m;
        int seq[n+m]={0},a[n]={0},b[m]={0};
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        int i=0,j=0;
        while(i<n or j<m){
            if(i < n){
                if(a[i]<=k){
                    if(a[i]==0)
                        k++;   
                    seq[i+j]=a[i];
                    i++;
                    continue;
                }
            }
            if(j < m){
                if(b[j]<=k){
                    if(b[j]==0)
                        k++;
                    seq[i+j]=b[j];
                    j++;
                    continue;
                }
            }
            break;
        }
        if(i==n and j==m){
            for(auto it: seq){
                cout<<it<<' ';
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}