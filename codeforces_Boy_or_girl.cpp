#include <bits/stdc++.h>

using namespace std;

int main(){
    set<char> dc;
    string s;
    cin>>s;
    for(auto c:s)
        dc.insert(c);
    if(dc.size()%2){
        cout<<"IGNORE HIM!"<<endl;
    }else{
        cout<<"CHAT WITH HER!"<<endl;
    }


    return 0;
}