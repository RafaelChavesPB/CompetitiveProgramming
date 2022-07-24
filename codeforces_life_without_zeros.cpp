#include <bits/stdc++.h>
using namespace std;
string remove_0(string a){
    string a_m;
    for(auto c:a){
        if(c!='0'){
            a_m+=c;
        }
    }
    return a_m;
}
int main(){
    string a,a_m,b,b_m;
    string sum,sum_m;
    cin>>a>>b;
    sum=remove_0(to_string(stoi(a)+stoi(b)));
    a_m=remove_0(a);
    b_m=remove_0(b);
    sum_m=to_string(stoi(a_m)+stoi(b_m));
    if(sum==sum_m){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
