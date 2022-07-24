#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,a,b,cont=1;
    while(cin>>n,n){
        int dif=0;
        cout<<"Teste "<<cont++<<endl;
        while(n--){
            cin>>a>>b;
            dif+=a-b;
            cout<<dif<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}