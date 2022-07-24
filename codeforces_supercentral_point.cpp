#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=0;j<n;j++){
            if(p[i].second == p[j].second){
                if(p[i].first < p[j].first){
                    flag |= 1 << 0;
                }else if(p[i].first > p[j].first){
                    flag |= 1 << 1;
                }
            }
            if(p[i].first == p[j].first){
                if(p[i].second < p[j].second){
                    flag |= 1 << 2;
                }else if(p[i].second > p[j].second){
                    flag |= 1 << 3;
                }
            }
        }
        if(flag==15){
            ans++;
        }
    }
    cout<<ans<<endl;
        
    return 0;
}