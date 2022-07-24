#include<bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    for(int i=0;i!=a.size() and i!=b.size();i++){
        if(tolower(a[i])<tolower(b[i])){
            return true;
        }else if(tolower(a[i])>tolower(b[i])){
            return false;
        }
    }
    if(a.size()<b.size()){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,tam;
    string temp;
    vector<string> v;
    while(cin>>n>>tam and n and tam){

        for(int i=0;i<tam;i++){
            v.push_back("");
        }
        for(int i=0;i<n;i++){
            cin>>temp;
            for(int j=0;j<tam;j++){
                v[j]+=temp[j];
            }
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0; i<n; i++){
            for(int j=0;j<tam;j++){
                cout<<v[j][i];
            }
            cout<<endl;
        }
        
        v.clear();
    }

    return 0;
}