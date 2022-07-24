#include <bits/stdc++.h>

using namespace std;

int main(){

    int x, y;
    scanf("%d %d",&x,&y);
    for(int i=1;i<=y;i++){
        printf("%d%c",i,(i%x==0?'\n':' '));
    }

    return 0;
}