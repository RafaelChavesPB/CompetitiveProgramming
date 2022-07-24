#include <bits/stdc++.h>
#define pi pair<int,int>
#define ti pair<int,pi>
using namespace std;
int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};
vector<string> input;
vector<vector<int>> m;
int r,c;
bool thereIsAWolf(int i, int j){
    return i>=0 and i<r and j>=0 and j<c and input[i][j]=='W';
}
bool chooseThePig(int i, int j){
    ti best(INT_MAX,pi(i,j));
    for(int k=0;k<4;k++){
        int a=i+di[k];
        int b=j+dj[k];
        if(a>=0 and a<r and b>=0 and b<c and m[a][b])
            best=min(ti(m[a][b],pi(a,b)),best);    
    }
    m[best.second.first][best.second.second]=0;
    return best.first<5;
}
int main()
{
    int ans = 0;
    cin >> r >> c;
    m.assign(r, vector<int>(c, 0));
    input.assign(r,"");
    for (int i = 0; i < r; i++)
    {
        cin>>input[i];
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(input[i][j]=='P')
                for(int k=0;k<4;k++)
                    m[i][j]+=thereIsAWolf(i+di[k],j+dj[k]);

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(input[i][j]=='W')
                ans+=chooseThePig(i,j);

    cout<<ans<<endl;
    return 0;
}