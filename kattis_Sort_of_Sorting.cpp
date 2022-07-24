#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    if(a[0]<b[0]){
        return true;
    }
    if(b[0]<a[0]){
        return false;
    }
    if(a[1]<b[1]){
        return true;
    }
    if(b[1]<a[1]){
        return false;
    }
    return false;
}

int main(){
    bool first=true;
    int n;
    string temp;
    vector<string> v; 

    while(cin>>n, n){
        if(!first){
            cout<<endl;
        }
        v.clear();
        first=false;
        while(n--){
            cin>>temp;
            v.push_back(temp);         
        }
        stable_sort(v.begin(),v.end(),compare);
        for(auto x:v){
            cout<<x<<endl;
        }
    }

    return 0;
}