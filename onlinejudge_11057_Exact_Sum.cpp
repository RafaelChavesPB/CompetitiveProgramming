#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,temp,dinh,resto, ans_a=0, ans_b=INT_MAX;
    vector<int> v;
    while(cin>>n){
        ans_a=0, ans_b=INT_MAX;
        v.clear();
        for(int i=0;i<n; i++){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        cin>>dinh;
        for(int i=0; i<n-1;i++){
            resto=dinh-v[i];
            if(binary_search(v.begin()+i,v.end(),resto)){
                if(abs(v[i]-resto)<abs(ans_a-ans_b)){
                    ans_a=v[i];
                    ans_b=resto;
                }
            }
        }
        cout<<"Peter should buy books whose prices are "<<ans_a<<" and "<<ans_b<<"."<<endl<<endl;
    }

    return 0;
}