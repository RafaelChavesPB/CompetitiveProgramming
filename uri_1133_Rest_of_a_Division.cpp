#include <bits/stdc++.h>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    for(int i=min(a,b)+1;i<max(a,b);i++){
        if(i%5==2 or i%5==3){
            cout<<i<<"\n";
        }
    }
    return 0;
}