#include <bits/stdc++.h>
using namespace std;
int result(long long n){
    string num = to_string(n);
    int acc=n;
    while(num.size()>1){
        acc=0;
        for(auto c:num){
            acc+=c-'0';
        }
        num=to_string(acc);
    }
    return acc;
}

int main(){
    long long n;
    while(cin>>n, n){
        cout<<result(n)<<endl;
    }
}