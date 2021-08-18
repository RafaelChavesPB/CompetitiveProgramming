#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        vector<int> indices = {0};
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                indices.push_back(i);
            }
        }
        for(int i=1;i<indices.size();i++){
            reverse(s.begin()+indices[i-1]+1,s.begin()+indices[i]);
        }
        cout<<s<<endl;
    }
}