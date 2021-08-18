#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int arr[10]={0};
    cin>>s;
    for(auto it: s)
        arr[it-'0']++;
    if(arr[4]==0 and arr[7]==0){
        cout<<-1<<endl;
    }else if(arr[4]>=arr[7]){
        cout<<4<<endl;
    }else{
        cout<<7<<endl;
    }
    return 0;
}