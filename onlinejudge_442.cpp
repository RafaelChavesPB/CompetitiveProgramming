#include <bits/stdc++.h>
using namespace std;

map<char,pair<int,int>> dict;
long long ans=0;
int it=0;
string expression;

bool valid(pair<int,int> a, pair<int,int> b){
    return a.second==b.first;
}

pair<int,int> chain(pair<int,int> a, pair<int,int> b){
    if(valid(a,b)){
        ans+=a.first*b.first*b.second;
    }else{
        ans=-INT_MAX;
    }
    return {a.first,b.second};
}

pair<int,int> rec(){
    vector<pair<int,int>> op;
    while(it<expression.size() and expression[it]!=')'){
        if(expression[it]=='('){
            it++;
            op.push_back(rec());
        }else{
            op.push_back(dict[expression[it]]);
            it++;
        }
    }    
    it+=expression[it]==')';
    if(op.size()==2)
        return chain(op.front(),op.back());
    else
        return op.front();
}

int main(){
    int n,a,b;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>a>>b;
        dict[c]={a,b};
    }
    while(cin>>expression){
        it=0;
        ans=0;
        while(it!=expression.size()){
            rec();
        }


        if(ans>=0)
            cout<<ans<<endl;
        else
            cout<<"error"<<endl;
    }
    return 0; 
}