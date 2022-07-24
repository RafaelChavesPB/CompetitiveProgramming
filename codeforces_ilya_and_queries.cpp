#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    string s;
    cin>>s>>n;
    s=' '+s+' ';
    vector<int> pfa(s.size());
    for(int i=1;i<s.size()-1;i++){
        pfa[i] = pfa[i-1] + (s[i]==s[i+1]);
        // cout<<(s[i]==s[i+1])<<' ';
    }
    while(n--){
        cin>>a>>b;
        cout<<pfa[b-1]-pfa[a-1]<<endl;
    }
    return 0;
}