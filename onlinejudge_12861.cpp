#include <bits/stdc++.h>
#define debug(x,y) cout<<x<<' '<<y<<endl
#define _debug(x) cout<<x<<endl
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a=0, b=0, c;
        vector<int> v;
        map<int,int> freq;
        for(int i=0;i<n;i++){
            cin>>c;
            freq[c]++;
        }
        for(auto x : freq){
            if(x.second%2){
                v.push_back(x.first);
            }
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i+=2){
            int temp=abs(v[i]-v[(i+1)%v.size()]);
            a+=min(temp,24-temp);
        }
        for(int i=1;i<v.size();i+=2){
            int temp=abs(v[i]-v[i-1]);
            b+=min(temp,24-temp);
        }
        cout<<min(a,b)<<endl;
    }
    return 0;
}