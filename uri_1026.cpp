#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int a,b,c;    

    // while(cin>>a>>b){
    //     cout<<(a ^ b)<<endl;        
    // }

    while(scanf("%d",&a) != EOF)
    {
        scanf("%d",&b);
        c=a^b;
        printf("%d\n",c);
    }
    
}