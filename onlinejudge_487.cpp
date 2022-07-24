#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
vector<vector<int>> visit;
vector<string> grid;
unordered_set<string> words;
bool compare(string a, string b){
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}
bool inGrid(int i,int j, int n){
    return i>=0 and i<n and j>=0 and j<n and !visit[i][j];
} 
void bt(int i,int j, string w){
    visit[i][j]=1;
    w+=grid[i][j];
    if(w.size()>=3)
        words.insert(w);
    for(auto d:dir){
        int a = i + d.first;
        int b = j + d.second;
        if(inGrid(a,b,grid.size())){
            if(w.back()<grid[a][b]){
                bt(a,b,w);
            }
        }
    }
    visit[i][j]=0;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        grid.clear();
        words.clear();
        visit.assign(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            grid.push_back("");
            cin>>grid.back();
        }
        for(int i = 0; i < n ; i++)
            for(int j = 0 ; j < n; j++)
                bt(i,j,string());
        vector<string> ans(words.begin(),words.end());
        sort(ans.begin(),ans.end(),compare);
        for(auto w:ans)
            cout<<w<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}