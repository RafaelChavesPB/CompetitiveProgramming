//Problema Disponível em: https://codeforces.com/problemset/problem/1506/D
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
    int t;
    cin>>t;
    while(t--){
        map<int,int> freq;
        priority_queue<PI,vector<PI>, less<PI>> pq;
        int n, temp;
        cin>>n;
        while(n--){
            cin>>temp;
            freq[temp]++;
        }
        for(auto it: freq)
            pq.push({it.S,it.F});
        while(pq.size()>1){
            PI first = pq.top();
            pq.pop();
            PI second = pq.top();
            pq.pop();
            if(first.F>1){
                first.F--;
                pq.push(first);
            }
            if(second.F>1){
                second.F--;
                pq.push(second);
            }
        }
        if(pq.size()){
            cout<<pq.top().F<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}