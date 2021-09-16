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
#define LIM 100001
using namespace std;


vector<string> pot;

int solveForANumber(string &p, string &n){
    int i = 0;
    int j = 0;
    int e = 0;
    while(i<p.size() and j<n.size())
        if(p[i] == n[j])
            e++, i++, j++;
        else
            j++;
    return p.size() + n.size() - 2*e;    
    
}

int solve(string n){
    int ans = INT_MAX;
    for(auto it:pot)
        ans = min(ans,solveForANumber(it,n));
    return ans;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    LL num = 1;
    for(int i = 0; i < 63; i++){
        pot.push_back(to_string(num));
        num *= 2;
    }   
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(to_string(n))<<endl;
    }
    return 0;
}