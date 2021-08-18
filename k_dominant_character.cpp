#include <bits/stdc++.h>
using namespace std;

vector<int> chars('z'-'a'+1);
string s;

bool test(char c, int k){
    int dist = 0;
    for(int j = 0; j < s.size(); j++){
        if(s[j]!=c){
            if(++dist==k)
                return false;
        }else{
            dist = 0;
        }
    }
    return true;
}

bool validate(int k){
    for(int i=0;i<chars.size();i++){
        if(chars[i]!=0){
            char c = 'a' + i;
            if(test(c,k)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int k;
    cin>>s;
    for(auto it: s)
        chars[it-'a']++;
    int l = 1;
    int r = s.size();
    int best = s.size();
    while(l<=r){
        int m = (l+r)/2;
        if(validate(m)){
            best = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout<<best<<endl;
    return 0;
}