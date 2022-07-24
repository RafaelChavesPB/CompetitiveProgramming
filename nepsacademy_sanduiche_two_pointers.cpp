#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n, d,dif, cont=0;
    cin>>n>>d;
    vector<int> v(2*n+1), prefix_sum(2*n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i+n]=v[i];
    }
    for(int i=1; i<=2*n;i++){
        prefix_sum[i]=v[i]+prefix_sum[i-1];
    }

    if(prefix_sum[n]<d){
        cout<<"0\n";
        return 0;
    }

    for(int i=1,j=2;i<=n;i++){
        while(prefix_sum[j]-prefix_sum[i-1]<d)
            j++;
        if(prefix_sum[j]-prefix_sum[i-1]==d){
            cont++;
        }
    }
    cout<<cont<<endl;

    return 0;
}