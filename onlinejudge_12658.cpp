#include <bits/stdc++.h>
using namespace std;
bool compare(vector<string> a, vector<string> b){
    for(int i=0;i<5;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
int main(){
    vector<string> c1 ={
        ".*.",".*.",".*.",".*.",".*."
    };
    vector<string> c2 ={
        "***","..*","***","*..","***"
    };
    vector<string> c3 ={
        "***","..*","***","..*","***"
    };
    int n;
    string temp;
    cin>>n;
    vector<vector<string>> ans(n);
    for(int i=0;i<5;i++){
        cin>>temp;
        for(int j=0;j<n;j++){
            ans[j].push_back(string(temp.begin()+j*4,temp.begin()+(j+1)*4-1));
        }
    }
    for(auto x:ans){
        // for(auto y:x){
        //     cout<<y<<endl;
        // }
        if(compare(x,c1))
            cout<<1;
        else if(compare(x,c2))
            cout<<2;
        else
            cout<<3;
    }
    cout<<endl;
    return 0;
}