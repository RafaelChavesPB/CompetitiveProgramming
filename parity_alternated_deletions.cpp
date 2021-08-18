#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    vector<int> even,odd;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2){
            odd.push_back(a);
        }else{
            even.push_back(a);
        }
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int tam = min(odd.size(),even.size())+1;
    int acc = 0;
    for(int i=0;i<(int)odd.size()-tam;i++){
        acc+=odd[i];
    }
    for(int i=0;i<(int)even.size()-tam;i++){
        acc+=even[i];
    }
    cout<<acc<<endl;
}