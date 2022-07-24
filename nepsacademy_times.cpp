#include<bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<pair<int,string>,vector<pair<int,string>>,less<pair<int,string>>> fp;
    vector<set<string>> times;
    pair<int,string> temp;
    int n,t;
    cin>>n>>t;
    times=vector<set<string>>(t);
    while(n--){
        cin>>temp.second>>temp.first;
        fp.push(temp);
    }
    int num=0;
    while(!fp.empty()){
        times[num++].insert(fp.top().second);
        fp.pop();
        num%=t;
    }
    for(int i=0;i<t;i++){
        cout<<"Time "<<i+1<<endl;
        for(auto j: times[i]){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}