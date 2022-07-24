#include <bits/stdc++.h>
using namespace std;
int main(){
    int cont=0;
    string in;
    while(cin>>in and in!="end"){
        vector<stack<char>> v(1);
        v[0].push('Z');
        for(auto x:in){
            bool ok=false;
            for(int i=0;i<v.size();i++){
                if(x<=v[i].top()){
                    v[i].push(x);
                    ok=true;
                    break;
                }
            }
            if(!ok){
                v.push_back(stack<char>());
                v.back().push(x);
            }
        }
        cout<<"Case "<<++cont<<": "; 
        cout<<v.size()<<endl;
    }
}