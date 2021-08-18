#include <bits/stdc++.h>
#define DEBUG 
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
#else
    #define bug(X) {;}
#endif

using namespace std;

int solve(const vector<string> &v, char c){
    vector<int> s(v.size());
    for(int i=0;i<s.size();i++){
        s[i] = 2 * count(v[i].begin(),v[i].end(),c) - v[i].size();
    }
    sort(s.begin(),s.end(),greater<int>());
    int q=0, acc=0;
    for(auto it: s){
        if(acc+it>0){
            q++;
            acc+=it;
        }else{
            break;
        }
    }
    return q;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> s(n);
        vector<vector<int>> freq(n,vector<int>(5,0));
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int ans = 0;
        for(char i='a';i<='e';i++){
            ans = max(solve(s,i),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}