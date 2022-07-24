//Problema disponível em: https://codeforces.com/problemset/problem/629/A
#include <bits/stdc++.h>
#define pi pair<int,int>
#define F first
#define S second

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> s(n);
    vector<pi> arr;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]=='C'){
                arr.push_back({i,j});
            }
        }
    }
    int ans = 0;
    for(int i=0;i<arr.size();i++)
        for(int j=i+1;j<arr.size();j++)
            ans+= (arr[i].F==arr[j].F or arr[i].S==arr[j].S);
    cout<<ans<<endl;
    return 0;
}