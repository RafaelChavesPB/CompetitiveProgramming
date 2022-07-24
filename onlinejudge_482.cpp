#include <bits/stdc++.h>
#define debug(s) cout<<(s)<<'\n' 
#define line() cout<<endl
#define  all(x) (x).begin(),(x).end()
using namespace std;
int main(){
    string in,s;
    istringstream ss;
    int t=5,n;
    cin>>t;
    getline(cin,s);
    while(t--){
        int it=0;
        vector<pair<int,string>> id;
        getline(cin,s);
        getline(cin,s);
        ss=istringstream(s);
        while(ss>>n){
            id.push_back({n,""});
        }
        getline(cin,s);
        ss=istringstream(s);
        while(ss>>in){
            id[it++].second=in;
        }
        sort(all(id));
        for(int i=0;i<id.size();i++){
            debug(id[i].second);
        }
        if(t)
            line();
    }
    return 0;
}