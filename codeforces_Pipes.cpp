#include <bits/stdc++.h>

using namespace std;


int main(){
    string entrada[2];
    int size,i,j,n;
    cin>>n;
    while(n--){
        cin>>size>>entrada[0]>>entrada[1];
        for(i=0,j=0; i<size;i++){
            if(entrada[j][i]-'0'>2){
                j=(!j);
                if(entrada[j][i]-'0'<=2){
                    break;
                }
            }
        }
        if(j==1 and i==size){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}