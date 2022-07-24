#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int a = i;
        int b = v[a]-1;
        int c = v[b]-1;
        if(a == v[c]-1){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}