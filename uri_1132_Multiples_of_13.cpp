#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b,total=0;
    cin>>a>>b;
    for(int i=min(a,b);i<=max(a,b);i++){
        if(i%13){
            total+=i;
        }
    }
    cout<<total<<"\n";
    return 0;
}