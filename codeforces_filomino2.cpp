//cp template.cpp filomino2.cpp && code filomino2.cpp
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 501
using namespace std;

int grid[LIM][LIM];

void fill(int i, int j, int r, int q){
    grid[i][j] = r; 
    if(q == 1){
        return;
    }
    if(j > 1 and grid[i][j-1] == 0)
        fill(i,j-1,r,q-1);
    else 
        fill(i+1,j,r,q-1);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR(1,n+1){
        FORJ(1,i+1){
            if(i == j)
                cin>>grid[i][j];
            else
                grid[i][j] = 0;
        }
    }
    FOR(1,n+1){
        fill(i,i,grid[i][i],grid[i][i]);
    }

    FOR(1,n+1){
        FORJ(1,i+1){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}