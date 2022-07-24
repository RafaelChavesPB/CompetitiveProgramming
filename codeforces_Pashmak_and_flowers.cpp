#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,maior=INT_MIN,menor=INT_MAX;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        maior=max(maior,b[i]);
        menor=min(menor,b[i]);
    }
    sort(b.begin(),b.end());
    long long x = upper_bound(b.begin(),b.end(),menor)-b.begin();
    long long y = b.end()-lower_bound(b.begin(),b.end(),maior);

    cout<<maior-menor<<' '<<(maior==menor?(x-1)*y/2:x*y)<<endl;
    return 0;
}