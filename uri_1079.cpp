#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    float v1,v2,v3;

    cout<<fixed<<setprecision(1);

    cin>>n;
    while(n--){
        cin>>v1>>v2>>v3;
        cout<<(v1*2+v2*3+v3*5)/10<<"\n";  
    }

    return 0;
}