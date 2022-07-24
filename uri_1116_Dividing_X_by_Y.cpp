#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases;
    float x, y;
    cin>>cases;
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(1);
    while(cases--){
        cin>>x>>y;
        if(y){
            cout<<x/y<<endl;
        }
        else{
            cout<<"divisao impossivel\n";
        }
    }
    return 0;
}