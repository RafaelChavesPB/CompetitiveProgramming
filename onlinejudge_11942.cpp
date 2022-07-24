#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    cout<<"Lumberjacks:"<<endl;
    while(t--){
        int n;
        vector<int> v;
        string ans="Ordered";
        for(int i=0;i<10;i++){
            v.push_back(0);
            cin>>v.back();
        }
        if(is_sorted(v.begin(),v.end(),greater<int>()) or is_sorted(v.begin(),v.end(),less<int>()))
            cout<<"Ordered"<<endl;
        else
            cout<<"Unordered"<<endl;
        
    }
    return 0;
}