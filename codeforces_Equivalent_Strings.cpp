#include <bits/stdc++.h>

using namespace std;

map<string,bool> memory;

bool rec(string a, string b){
    if(a.size()==1){
        return a==b;
    }
    
    string a1(a.begin(),a.begin()+a.size()/2);
    string a2(a.begin()+a.size()/2,a.end());
    string b1(b.begin(),b.begin()+b.size()/2);
    string b2(b.begin()+b.size()/2,b.end());
    
    if((a1==b1 and a2==b2) or (a1==b2 and a2==b1) or a==b)
        return  true;
    

    if(memory.find(a+b)!=memory.end())
        return memory[a+b];
    
    if(a1.size()==a2.size() and b2.size()==b1.size())
        return memory[a+b]=(rec(a1,b1) and rec(a2,b2)) or (rec(a1,b2) and rec(a2,b1));

    return false;
}
int main(){
    ios::sync_with_stdio(false);
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<(rec(a,b)?"YES\n":"NO\n");
    return 0;
}