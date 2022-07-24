#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    int i,j;
    for(i=a.size()-1, j=b.size()-1;i>=0 and j>=0; i--,j--){
        if(a[i]<b[j]){
            return true;
        }else if(b[j]<a[i]){
            return false;
        }
    }
    if(i==-1){
        return true;
    }
    return false;
}

int main(){
    string temp;
    vector<string> v;
    int tam_max=0;
    while(getline(cin,temp)){
        if(temp.empty()){
            sort(v.begin(),v.end(),compare);
            for(auto x: v){
                cout<<setw(tam_max)<<right<<x<<endl;
            }
            cout<<endl;
            v.clear();
            tam_max=0;
        }else{
            
            v.push_back(temp);
            tam_max=max(tam_max,int(temp.size()));
        }
    }
    sort(v.begin(),v.end(),compare);
    for(auto x: v){
        cout<<setw(tam_max)<<right<<x<<endl;
    }
    return 0;
}