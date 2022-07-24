#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int tam, int a, int b, int c)
{
    if(tam < 0)
        return -1e5;
    if(tam == 0)
        return 0;
    if(dp[tam] != -1)
        return dp[tam];

    int x = solve(tam-a,a,b,c)+1;
    x = max(solve(tam-b,a,b,c)+1,x);
    x = max(solve(tam-c,a,b,c)+1,x);
    dp[tam]=x;
    return dp[tam]; 
}
int main()
{
    int a,b,c,tam;
    cin>>tam>>a>>b>>c;
    dp.assign(tam+1,-1);
    cout<<solve(tam,a,b,c)<<endl;
    return 0;
}