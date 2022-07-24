#include <bits/stdc++.h>
using namespace std;
int result(string num){
    int acc=0;
    for(auto c:num){
        if(c>='a' and c<='z')
            acc+=c + 1 -'a';
        else if(c>='A' and c<='Z')
            acc+=c + 1 -'A';
    }
    num=to_string(acc);

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
    string a,b;
    while(getline(cin,a)){
        double p_a=result(a);
        getline(cin,b);
        double p_b=result(b);
        cout<<fixed<<setprecision(2)<<min(p_b,p_a)*100/max(p_b,p_a)<<" %"<<endl;
    }
}