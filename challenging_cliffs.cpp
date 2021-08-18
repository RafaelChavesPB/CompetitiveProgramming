#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        pair<int,pair<int,int>> diff_init = {v[1]-v[0],{0,1}}; 
        pair<int,pair<int,int>> diff_end = {v[n-1]-v[n-2],{n-2,n-1}}; 
        pair<int,pair<int,int>> diff_middle = {INT_MAX,{0,0}};
        for(int i=1;i<n-2;i++){
            if(diff_middle.first>v[i+1]-v[i]){
                diff_middle = {v[i+1]-v[i],{i,i+1}};
                // cout<<v[i]<<' '<<v[i+1]<<endl;
            }
        }
        // cout<<diff_init.first<<' '<<diff_end.first<<endl;
        if(diff_middle.first<diff_init.first and diff_middle.first<diff_end.first){
            cout<<v[diff_middle.second.first]<<' ';
            for(int i=0;i<n;i++){
                if(v[i]>=v[diff_middle.second.second] and i!=diff_middle.second.first and i!=diff_middle.second.second){
                    cout<<v[i]<<' ';
                }
            }
            for(int i=0;i<n;i++){
                if(v[i]<v[diff_middle.second.first] and  i!=diff_middle.second.first and i!=diff_middle.second.second){
                    cout<<v[i]<<' ';
                }
            }
            cout<<v[diff_middle.second.second]<<endl;
        }else if(diff_init.first<diff_end.first){
            cout<<v[diff_init.second.first]<<' ';
            for(int i = 2; i < n; i ++){
                cout<<v[i]<<' ';
            }
            cout<<v[diff_init.second.second]<<endl;
        }else{
            cout<<v[diff_end.second.first]<<' ';
            for(int i = 0; i < n-2; i ++){
                cout<<v[i]<<' ';
            }
            cout<<v[diff_end.second.second]<<endl;
        }
    }
    return 0;
}