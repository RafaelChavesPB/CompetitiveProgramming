#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a , pair<int,int> b){
    return a.second<b.second;
}
int main(){
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;
    vector<int> bzinho;
    int n,tempzinho;
    pair<int,int> temp;
    while(cin>>n and n){
        a.clear();
        b.clear();
        bzinho.clear();
        for(int i=0;i<n;i++){
            cin>>temp.first;
            temp.second=i;
            a.push_back(temp);
        }
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            cin>>tempzinho;
            bzinho.push_back(tempzinho);
        }

        sort(bzinho.begin(),bzinho.end());

        for(int i=0; i<n; i++){
            temp={bzinho[i],a[i].second};
            b.push_back(temp);
        }

        sort(b.begin(),b.end(),compare);

        for(auto x: b){
            cout<<x.first<<endl;
        }
        cout<<endl;
    }


    return 0;
}