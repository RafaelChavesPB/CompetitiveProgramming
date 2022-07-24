#include <bits/stdc++.h>
#define ll pair<long,long>
#define s second
#define f first

using namespace std;

void encontra(long x, long lado){

    long i,j,count;

    
    if(lado%2){

       if(lado*lado==x){
               cout<<1<<" "<<lado<<endl;
               return;
        }
       
       i=1;j=lado+1, count=j*j;
       
       if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
        }

       for(int n=0; n<lado;n++,count--,i++)
       {
           if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
           }
       }
       for(int n=0; n<lado;n++,count--,j--)
       {
           if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
           }
       }
       if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
       }
    }

    else{
       if(lado*lado==x){
               cout<<lado<<" "<<1<<endl;
               return;
        }
       
       j=1;i=lado+1, count=i*i;
       
       for(int n=0; n<lado;n++,count--,j++)
       {
           if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
           }
       }
       for(int n=0; n<lado;n++,count--,i--)
       {
           if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
           }
       }
       if(count==x){
               cout<<j<<" "<<i<<endl;
               return;
       }
    }

    
}

int main (){
    
    long x, l;
    while(cin>>x&&x){
        l=(int)sqrt(x);
        encontra(x,l);
    }
    return 0;
}