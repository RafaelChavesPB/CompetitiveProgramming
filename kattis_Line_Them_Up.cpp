#include <bits/stdc++.h>

using namespace std;

void print(string a){
    cout<<a<<endl;
}
int main(){
    string temp;
    vector<string> v;
    int n;
    
    cin>>n;
    
    while(n--){
        cin>>temp;
        v.push_back(temp);
    }
    
    if(is_sorted(v.begin(),v.end())){
        cout<<"INCREASING"<<endl;
    }else if(reverse(v.begin(),v.end()),is_sorted(v.begin(),v.end())){
        cout<<"DECREASING"<<endl;
    }else{
        cout<<"NEITHER"<<endl;
    }
    return 0;
}
