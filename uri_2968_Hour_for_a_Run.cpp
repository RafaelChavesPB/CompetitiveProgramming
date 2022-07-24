#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, tabuas, total, parcial;
    cin>>n>>tabuas;
    total=n*tabuas;
    for(int i=1; i<10;i++){
        parcial=i*total;
        if(parcial%10){
            printf("%d%c",(parcial/10)+1,(i==9?'\n':' '));
        }else{
            printf("%d%c",(parcial/10),(i==9?'\n':' '));
        }
    }
}