#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    while(getline(cin,in)){
        string out;
        string word;
        istringstream buff(in);
        while(buff>>word){
            reverse(word.begin(),word.end());
            out+=word+' ';
        }
        out.back()='\n';
        cout<<out;
    }
    return 0;
}