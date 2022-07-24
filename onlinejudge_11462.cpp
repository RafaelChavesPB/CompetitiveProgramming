#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,lim=2000001;
    vector<int> v(lim,0);
    ios::sync_with_stdio(false);
    while(cin>>n,n){
        int cont=0;
        int a;
        while(n--){
            cin>>a;
            v[a]++;
        }
        for(int i=1;i<lim;i++){
            while(v[i]!=0){
                if(cont++){
                    cout<<' ';
                }
                v[i]--;
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}