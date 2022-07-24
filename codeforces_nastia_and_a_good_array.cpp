#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
       for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(arr.size()%2){
            cout<<n/2<<endl;
            for(int i=1;i<n;i+=2){
                int b=1732066891;
                int c=min(arr[i],arr[i+1]);
                arr[i] = b;
                arr[i+1] = c;
                cout<<i+1<<' '<<i+2<<' '<<b<<' '<<c<<endl;
            }
        }else{
            cout<<n/2<<endl;
             for(int i=1;i<n;i+=2){
                 if(i!=n-1){
                    int b=1732066891;;
                    int c=min(arr[i],arr[i+1]);
                    arr[i] = b;
                    arr[i+1] = c;
                    cout<<i+1<<' '<<i+2<<' '<<b<<' '<<c<<endl;
                 }else{
                    int c = 1732066891;
                    int b = min(arr[n-1],arr[n-2]);
                    cout<<n-1<<' '<<n<<' '<<b<<' '<<c<<endl;
                 }
            }
        }
    }
    return 0;
}