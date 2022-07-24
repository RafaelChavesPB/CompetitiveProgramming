#include <bits/stdc++.h>
using namespace std;
int m;
bool compare(int a, int b){
    if((a%m)==(b%m)){
        if(a%2 and b%2){
            return a>b;
        }else if(a%2 and b%2==0){
            return true;
        }else if(a%2==0 and b%2){
            return false;
        }else{
            return a<b;
        }
    }
    return (a%m)<(b%m);
}
int main(){
    int n;
    while(cin>>n>>m,n and m){
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),compare);
        cout<<n<<' '<<m<<endl;
        for(auto x:v){
            cout<<x<<endl;
        }
    }
    cout<<0<<' '<<0<<endl;
    return 0;
}