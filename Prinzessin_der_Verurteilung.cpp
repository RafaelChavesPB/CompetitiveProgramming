#include <bits/stdc++.h>
using namespace std;

set<string> substr;

void generate(string str, int tam){
    if(tam==0){
        substr.insert(str);
        return;
    }
    for(char i='a';i<='z';i++)
        generate(str+i,tam-1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string input;
        cin>>n;
        cin>>input;
        int tam = 0;
        while(true){
            substr.clear();
            generate("",++tam);
            for(int i=0; i<=n-tam;i++){
                substr.erase(input.substr(i,tam));
            }
            if(substr.size())
                break;
        }
        for(auto it: substr){
            cout<<it<<endl;
            break;
        }
    }
    return 0;
}