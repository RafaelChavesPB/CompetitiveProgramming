#include <bits/stdc++.h>
using namespace std;
int main(){
    set<string> dict;
    string in;
    while(getline(cin,in)){
        string atual;
        for(auto a:in ){
            if(isalpha(a)){
                atual+=tolower(a);
            }else{
                if(atual!="")
                    dict.insert(atual);
                atual.clear();
            }
        }
        if(atual!="")
            dict.insert(atual);
    }
    for(auto s:dict){
        cout<<s<<endl;
    }
    return 0;
}