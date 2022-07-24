#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,m,a,b,d;
    vector<vector<int>> grid(251,vector<int>(251,98765432));

    cin>>n>>m;
    while(m--){
        cin>>a>>b>>d;
        grid[a][b]=grid[b][a]=d;
    }

    for(int k=1;k<=n;k++){
        grid[k][k]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                grid[i][j]=grid[j][i]=min(grid[i][j],grid[i][k]+grid[k][j]);
            }
        }
    }

    int ans=987654321;
    for(int i=1;i<=n;i++){
        int maxi=-987654321;
        for(int j=1;j<=n;j++){
            maxi=max(maxi,grid[i][j]);
        }
        ans=min(ans,maxi);
    }

    cout<<ans<<endl;

    return 0;
}