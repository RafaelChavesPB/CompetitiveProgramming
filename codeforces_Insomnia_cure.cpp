#include <bits/stdc++.h>

using namespace std;
int main(){
    int k,l,m,n,d, count=0;
    cin>>k>>l>>m>>n>>d;
    for(int i=1; i<=d;i++){
        if(!(i%k) or !(i%l) or !(i%m) or !(i%n)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}