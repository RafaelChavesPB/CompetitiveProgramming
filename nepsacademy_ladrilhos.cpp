#include <bits/stdc++.h>

using namespace std;

int mem[202][202];
int dl[]={0,1,0,-1};
int dc[]={1,0,-1,0};

bool ingrid(int l, int c, int n, int m){
    return l>=0 and l<n and c>=0 and c<m;
}

int dfs(int l, int c, int n,int m, int valor){
    int tl, tc, total=0;
    mem[l][c]=-1;
    for(int i=0;i<4;i++){
        tl=l+dl[i];
        tc=c+dc[i];
        if(ingrid(tl,tc,n,m) and mem[tl][tc]==valor){
            total+=dfs(tl,tc,n,m,valor);
        }
    }
    return total+1;
}

int main(){
    int n, m, ans=INT_MAX;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mem[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mem[i][j]!=-1){
                ans=min(ans,dfs(i,j,n,m,mem[i][j]));
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}