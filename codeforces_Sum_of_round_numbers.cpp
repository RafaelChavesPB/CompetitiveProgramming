#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,num;
    cin>>n;
    while(n--){
        vector<int> v;
        int rest;
        cin>>num;
        for(int i=1;i<=5;i++){
            rest=num%int(pow(10,i));
            if(rest){
                v.push_back(rest);
            }
            num-=rest;
        }
        cout<<v.size()<<endl;
        for(auto x:v){
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return 0;
}