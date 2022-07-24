#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    string b="aabb";
    cin>>n;
    int i=0;
    while(n--){
        s+=b[i++];
        i%=4;
    }
    cout<<s<<endl;
}