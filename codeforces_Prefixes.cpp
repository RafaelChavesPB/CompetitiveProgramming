#include <bits/stdc++.h>

using namespace std;


int main(){

    char str[200010];
    int count=0;
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    
    for(int i=0;i<n-1;i+=2){
        if(str[i]==str[i+1]){
            count++;
            if(str[i]=='a'){
                str[i]='b';
            }else{
                str[i]='a';
            }
        }
    }

    printf("%d\n%s\n",count,str);
        

    return 0;
}