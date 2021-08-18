#include <bits/stdc++.h>

using namespace std;

int di[] = {1, 0};
int dj[] = {0, 1};
vector<string> grid;
vector<vector<int>> dp;

int dfs(int i, int j){
    if(grid[i][j]=='2')
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=0;
    for(int k = 0; k < 2; k++){
        int ni = i + di[k];
        int nj = j + dj[k]; 
        if(grid[ni][nj]!='0')
            dp[i][j] = max(dfs(ni,nj),dp[i][j]); 
    }
    return dp[i][j];
}

int main(){
    int t = 0;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        grid.clear();
        dp.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            grid.push_back(temp+'2');
        }
        string temp(n,'2');
        bool allright = true;
        grid.push_back(temp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1')
                    allright*=dfs(i,j);
            }
        }
        if(allright){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

