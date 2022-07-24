#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        long long acc = 5000000;
        bool flag=true;
        vector<int> v;
        while(cin>>a, a){
            v.push_back(a);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i=0;i<v.size();i++){
            long long a = 2 * pow(v[i], i+1);
            if(a>acc){
                flag=false;
                break;
            }else{
                acc-=a;
            }
        }
        if(flag)
            cout<<5000000-acc<<endl;
        else
            cout<<"Too expensive"<<endl;   
    }
    return 0;
}