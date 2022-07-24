//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugC(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
#else
    #define bug(X) {;}
    #define bugC(X) {;}
    #define bugV(X,N) {;}
    #define bugM(X,N,M) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define LLMAX 123456789012345
#define LLMIN -123456789012345
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(q.size()){
        int curr = q.front();
        q.pop();
        FORIT(adj[curr]){
            if(!visited[IT]){
                visited[IT] = visited[curr] % 2 + 1;
                q.push(IT);
            }else if(visited[IT] == visited[curr]){
                return true;
            }
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    cin >> n;
    adj.resize(n);
    visited.assign(n,0);
    FOR(0,n){
        FORJ(0,n){
            cin >> temp;
            if(!temp){
                adj[I].PB(J);
                adj[J].PB(I);
            }
        }
    }

    string ans = "Bazinga!";
    FOR(0,n){
        if(!visited[I]){
            if(bfs(I)){
                ans = "Fail!";
            }
        }
    }

    cout << ans << endl;

    return 0;
}