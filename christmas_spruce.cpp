#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> parent(n),childs_number(n),leaf_childs(n); 
    for(int i=1;i<n;i++){
        cin>>parent[i];
        parent[i]--;
        childs_number[parent[i]]++;
    }
    for(int i=0;i<n;i++){
        if(childs_number[i] == 0){
            leaf_childs[parent[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        if(childs_number[i]!=0 and leaf_childs[i]<3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}