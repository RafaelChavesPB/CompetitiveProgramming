#include <bits/stdc++.h>

using namespace std;


int main(){
    int cases,n,count;
    cin>>cases;
    while(cases--){
        cin>>n;
        count=0;
        while(true){
            if(n%6==0){
                count++;
                n/=6;
            }else if(n%3==0){
                n/=3;
                count+=2;
            }else if(n==1){
                cout<<count<<endl;
                break;
            }else{
                cout<<-1<<endl;
                break;
            }
        }
    }



}