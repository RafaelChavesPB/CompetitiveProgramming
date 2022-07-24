#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<pair<int,int>> dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},
                            {1,-2},{-1,-2},{-2,-1}};
bool  inGrid(int i, int j){
    return i>=0 and i<8 and j>=0 and j<8 and !grid[i][j];
}
int bfs(pair<int,int> p, pair<int,int> d){
    queue<pair<pair<int,int>,int>> fila;
    grid.assign(8,vector<int>(8,0));
    fila.push({p,0});
    grid[p.first][p.second]=1;
    while(!fila.empty()){
        if(fila.front().first==d)
            return fila.front().second;
        auto i=fila.front().first.first;
        auto j=fila.front().first.second;
        auto dist=fila.front().second;
        fila.pop();
        for(auto it:dir){
            int a=i+it.first;
            int b=j+it.second;
            if(inGrid(a,b)){
                fila.push({{a,b},dist+1});
                grid[a][b]=1;
            }
        }
    }
    return -1;
}
int main(){
    string source, dest;
    while(cin>>source>>dest)
    {
        pair<int,int> s = {source[0]-'a',source[1]-'1'};
        pair<int,int> d = {dest[0]-'a',dest[1]-'1'};
        cout<<"To get from "<<source<<" to "<< dest << " takes "<<bfs(s,d)<<" knight moves."<<endl;
    }
    return 0;
}