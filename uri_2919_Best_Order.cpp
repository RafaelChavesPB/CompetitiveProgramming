#include <bits/stdc++.h>

using namespace std;


int memory[500020];
int seq[500020];

int lis(int n){
   int res, max_ending_here=1;
   if(n==1){
       memory[0]=1;
       return 1;
   }
   if(memory[n-1]){
       return memory[n-1];
   }
   for(int i=1;i<n;i++){
       res=lis(i);
       if(seq[i-1]<seq[n-1]&&res+1>max_ending_here){
           max_ending_here=res+1;
       }
   }
   memory[n-1]=max_ending_here;
   return max_ending_here;
}

int _lis(int n){
   int maior=INT_MIN;

   for(int i=0;i<n;i++){
       memory[i]=0;
   }

   lis(n);

   for(int i=0;i<n;i++){
       if(memory[i]>maior){
           maior=memory[i];
       }
   }

   return maior;
}


int main(){
    int n, temp;

    ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>seq[i];
        }
        cout<<_lis(n)<<"\n";
    }

    
    return 0;
}