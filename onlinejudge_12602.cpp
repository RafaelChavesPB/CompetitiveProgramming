#include <bits/stdc++.h>

using namespace std;

int separa(char *str, char *alpha){
    
    strncpy(alpha,str,3);
    alpha[3]='\0';
    return atoi(&str[4]);
}

int main(){

    char str[9],alpha[4];
    int value,p1,p2,n;
    
    cin>>n;
    while(n--){

        scanf("%s",str);
        value=separa(str,alpha);
        p1=(alpha[0]-65)*26*26+(alpha[1]-65)*26+(alpha[2]-65);
        if(abs(p1-value)<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}

