#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(1);
        cout<<3*n<<endl;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        for(int i=1;i<=n;i+=2){
            cout<<1<<' '<<i<<' '<<i+1<<endl;
            arr[i]+=arr[i+1];
            cout<<1<<' '<<i<<' '<<i+1<<endl;
            arr[i]+=arr[i+1];
            cout<<2<<' '<<i<<' '<<i+1<<endl;
            arr[i+1]-=arr[i];
            cout<<1<<' '<<i<<' '<<i+1<<endl;
            arr[i]+=arr[i+1];
            cout<<1<<' '<<i<<' '<<i+1<<endl;
            arr[i]+=arr[i+1];
            cout<<2<<' '<<i<<' '<<i+1<<endl;
            arr[i+1]-=arr[i];
        }
        // for(int i=1;i<=n;i++){
        //     cout<<arr[i]<<' ';
        // }
        // cout<<endl; 
    }   
    return 0;
}