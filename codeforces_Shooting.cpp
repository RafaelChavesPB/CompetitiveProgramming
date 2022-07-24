#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

bool compare(pi a, pi b){
    return a.f > b.f;
}

int main(){
    int n,x=0, shoots=0;
    pi temp;
    vector<pi> cans;

    cin>>n;
    for(int i=0; i<n;i++){
        cin>>temp.f;
        temp.s=i;
        cans.push_back(temp);
    }

    sort(cans.begin(),cans.end(), compare);

    for(auto it: cans){
        shoots+=it.f*x+1;
        x++;
    }

    cout<<shoots<<endl;

    for(auto it: cans){
        cout<<it.s+1<<" ";
    }
    cout<<endl;


    return 0;
}