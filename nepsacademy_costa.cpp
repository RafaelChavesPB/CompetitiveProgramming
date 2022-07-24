#include <bits/stdc++.h>

using namespace std;
bool ingrid(int x, int y, int mx, int my){
    if(x<0 or x==mx){
        return 0;
    }
    if(y==0 or y>my){
        return 0;
    }
    return 1;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
    int n,m, ans=0;
    bool ifound;
    string mapa[1002];
    cin>>m>>n;
    for(int i=1; i<=m; i++){
        cin>>mapa[i];
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            ifound=0;
            for(int k=0;k<4;k++){
                if(ingrid(j+dx[k],i+dy[k],n,m)){
                    if(mapa[i+dy[k]][j+dx[k]]=='.' and mapa[i][j]=='#'){
                        ifound=1;
                    }
                }else
                {
                    if(mapa[i][j]=='#'){
                        ifound=1;
                    }
                }
            }
            if(ifound){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}