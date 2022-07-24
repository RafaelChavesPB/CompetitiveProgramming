#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,temp;
    vector<string> v;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            v.push_back(temp);
            temp.clear();
        }
        temp+=s[i];
    }
    v.push_back(temp);
    string ans="YES";
    for(auto i: v){
        if(!i.empty() and i!="1" and i!="14" and i!="144"){
            ans="NO";
        }
    }
    cout<<ans<<endl;
    return 0;
}