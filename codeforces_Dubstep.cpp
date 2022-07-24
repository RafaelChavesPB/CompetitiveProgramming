#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    deque<char> ans;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]!='W'){
            ans.push_back(a[i]);
        }else if(string(a.begin()+i,a.begin()+i+3)!="WUB"){
            ans.push_back(a[i]);
        }else{
            i+=2;
            if(ans.empty() or ans.back()!=' ')
                ans.push_back(' ');
        }
    }
    if(ans.front()==' ')
        ans.pop_front();
    if(ans.back()==' ')
        ans.pop_back();
    cout<<string(ans.begin(),ans.end())<<endl;
    return 0;
}