#include <bits/stdc++.h>

using namespace std;

int main(){

    int x, y;
    while(cin>>x>>y&&x&&y){
        if(y>0){
            cout<<(x>0?"primeiro":"segundo")<<"\n";
        }else{
            cout<<(x<0?"terceiro":"quarto")<<"\n";
        }
    }
    return 0;
}