#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int max=INT_MIN;
    int pos=0;
    for(int i=1;i<=100;i++){
        cin>>n;
        if(n>max){
            max=n;
            pos=i;
        }
    }
    cout<<max<<"\n"<<pos<<"\n";
    return 0;
}