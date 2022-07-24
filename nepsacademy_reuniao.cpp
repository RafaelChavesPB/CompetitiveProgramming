#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> grid(101, vector<int>(101, 987654321));

int main()
{
    int a, b, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> w;
        if (grid[a][b] > w)
            grid[a][b] = grid[b][a] = w;
    }

    for(int k=1;k<=n;k++)
        grid[k][k]=0;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=grid[j][i]=min(grid[i][j],grid[i][k]+grid[k][j]);
            }
        }
    }
    int ans=987654321;
    for(int  i=0; i<n;i++){
        int maxi=-987654321;
        for(int j=0;j<n;j++){
            maxi=max(maxi,grid[i][j]);
        }
        ans=min(ans,maxi);
    }

    cout<<ans<<endl;
    return 0;
}