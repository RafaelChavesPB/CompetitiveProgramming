#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,a;
    cin>>t;
    while(t--){
        vector<int> v, preffix(1,0);
        cin>>n;
        while(n--){
            cin>>a;
            v.push_back(a);
            preffix.push_back(a+preffix.back());
        }
        int count=0;
        for(auto x: v){
            for(auto it=preffix.begin();it!=(preffix.end()-2);it++){
                int sum=*it+x;
                if(binary_search(it+2,preffix.end(),sum)){
                    count++;
                    break;
                }
            }
        }
        cout<<count<<endl;
    }

    return 0;
}