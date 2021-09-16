//Problema Disponível em: 
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
#define LIM 1001
using namespace std;

int parent[2][LIM];
int balalau[2][LIM];

int find_set(int v, int t) {
    if (v == parent[t][v])
        return v;
    return parent[t][v] = find_set(parent[t][v],t);
}

void make_set(int v, int t) {
    parent[t][v] = v;
    balalau[t][v] = 1;
}

void union_sets(int a, int b, int t) {
    a = find_set(a,t);
    b = find_set(b,t);
    if (a != b) {
        if (balalau[t][a] < balalau[t][b])
            swap(a, b);
        parent[t][b] = a;
        balalau[t][a] += balalau[t][b];
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,d;
    vector<pair<int,int>> ans;
    cin>>n>>m>>d;


    FOR(1,n+1){
        make_set(i,0);
        make_set(i,1);
    }

    while(m--){
        int a,b;
        cin>>a>>b;
        union_sets(a,b,0);
    }

    while(d--){
        int a,b;
        cin>>a>>b;
        union_sets(a,b,1);
    }

    FOR(1,n){
        FORJ(i+1,n+1){
            if(find_set(i,0) != find_set(j,0) and find_set(i,1) != find_set(j,1)){
                union_sets(i,j,0);
                union_sets(i,j,1);
                ans.push_back({i,j});
            }
        }
    }

    cout<<ans.size()<<endl;
    FOR(0,ans.size()){
        cout<<ans[i].F<<' '<<ans[i].S<<endl;
    }
    return 0;
}