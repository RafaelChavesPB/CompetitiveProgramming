#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y, total;
    cin>>n;
    while(n--){
        total=0;
        cin>>x>>y;
        for(int i=min(x,y)+1;i<max(x,y);i++){
            if(i%2){
                total+=i;
            }
        }
        cout<<total<<"\n";
    }


    return 0;
}