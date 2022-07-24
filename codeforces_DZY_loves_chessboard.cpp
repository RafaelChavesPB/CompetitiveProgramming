#include <bits/stdc++.h>
using namespace std;
vector<string> cb;

int r,c, di[]={0,0,1,-1},dj[]={1,-1,0,0}, l[]={'B','W'};

struct cell{
    int i,j,letter;
    cell(int i,int j, int letter){
        this->i=i;
        this->j=j;
        this->letter=letter;
    }
};

bool isGood(int i, int j){
    return i>=0 and i<r and j>=0 and j<c and cb[i][j]=='.'; 
}
void bfs(int i, int j, int letter){
    queue<cell> fila;
    fila.push(cell(i,j,letter));
    while(!fila.empty()){
        auto atual = fila.front(); 
        fila.pop();
        for(int k=0;k<4;k++){
            int y = atual.i + di[k];
            int x = atual.j + dj[k];
            if(isGood(y,x)){
                cb[y][x]=l[atual.letter];
                fila.push(cell(y,x,!atual.letter));
            }
        }
    }
}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cb.push_back("");
        cin>>cb.back();
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(cb[i][j]=='.'){
                bfs(i,j,0);  
                cb[i][j]=l[1];
            }
    for(auto s: cb)
        cout<<s<<endl;
    
    return 0;
}