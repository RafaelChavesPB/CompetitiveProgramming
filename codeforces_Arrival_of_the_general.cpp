#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,h;
    pair<int,int> minimo(10e+5,0), maximo(-10e+5,0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        if(h>maximo.first){
            maximo.first=h;
            maximo.second=i;
        }
        
        if(h<=minimo.first){
            minimo.first=h;
            minimo.second=i;
        }
    }
    int ans=maximo.second+n-minimo.second-1;
    if(minimo.second<maximo.second){
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}