//Problema disponível em: https://codeforces.com/problemset/problem/1515/C
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
#define PI pair<int,int>
#define LIM 100001

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<PI,vector<PI>,greater<PI>> pq;
    int t;
    int arr[LIM];
    cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        FOR(1,m+1){
            pq.push({0,i});
        }
        FOR(0,n){
            int value;
            cin>> value;
            PI tower = pq.top();
            pq.pop();
            tower.F+=value;
            pq.push(tower);
            arr[i] = tower.S;
        }
        int min_tower = pq.top().F;
        int max_tower;
        while (pq.size()){   
            max_tower = pq.top().F;
            pq.pop();
        }
        if(max_tower - min_tower <= x){
            cout<<"YES"<<endl;
            FOR(0,n){
                cout<<arr[i]<<' ';
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}