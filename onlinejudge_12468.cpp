#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b, a!=-1 and b!=-1){
        if(a<b){
            cout<<min(b-a, 100+a-b)<<endl;
        }else{
            cout<<min(100+b-a,a-b)<<endl;
        }
    }
}