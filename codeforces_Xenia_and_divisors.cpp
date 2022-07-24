#include <bits/stdc++.h>
using namespace std;

int main(){
    string s[]={"1 2 4","1 2 6","1 3 6"};
    int n, a, f[8]={0}, t[3]={0};
    bool valido = true;
    cin >> n;
    while(n--){
        cin>>a;
        if(a==5 or a==7)
            valido=false;
        else 
            f[a]++;
    }
    if(valido and f[4]<=f[2] and f[4]<=f[1]){
        f[2]-=f[4];
        f[1]-=f[4];
        t[0]=f[4];
        if(f[3]<=f[6] and f[3]<=f[1]){
            f[6]-=f[3];
            f[1]-=f[3];
            t[2]=f[3];
            if(f[1]==f[2] and f[2]==f[6]){
                t[1]=f[2];
                for(int i=0; i<=2; i++){
                    while(t[i]--){
                        cout<<s[i]<<endl;
                    }
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}