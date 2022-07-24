#include <bits/stdc++.h>
using namespace std;
double avg;
int main(){
    int n,m,a, cont=0;
    while(cin>>n>>m){
        double acc=0;
        vector<int> v(2*n);
        vector<pair<int,int>> ans(n); 
        for(int i=0;i<m;i++){
            cin>>v[i];
            acc+=v[i];
        }
        avg=acc/n;
        sort(v.begin(), v.end(), greater<int>());
        for(int i=0;i<n;i++){
            ans[i]={v[i],v[2*n-1-i]};
            // cout<<ans[i].first<<' '<<ans[i].second<<endl;
        }   
        double imbalance=0;
        cout<<"Set #"<<++cont<<endl;
        for(int i=0;i<n;i++){
            cout<<' '<<i<<':';
            if(ans[i].first){
                cout<<' '<<ans[i].first;
                if(ans[i].second)
                    cout<<' '<<ans[i].second;
            }
            imbalance+=abs(ans[i].first+ans[i].second-avg);
            cout<<endl;
        }
        cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<imbalance<<endl<<endl;
    }
    return 0;
}