//cp template.cpp web_of_lies.cpp && code web_of_lies.cpp
#include <bits/stdc++.h>
#define SUBMIT
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugS(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(auto it: X) cout<< it <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
    #define bugS(X) {;} 
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 200001
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,q;
    cin>>n>>m;
    vector<set<int>> friends(n+1);
    set<int> survivors;
    while(m--){
        cin>>a>>b;
        friends[a].insert(b);
        friends[b].insert(a);
    }
   
    FOR(1,n+1){
        if(friends[i].upper_bound(i)==friends[i].end()){
            survivors.insert(i);
        }
    }
    
    cin>>q;
    while(q--){
        int op,x,y;
        cin>>op;
        if(op==3){
            cout<<survivors.size()<<endl;
        }else{
            cin>>x>>y;
            if(op==2){
                friends[x].erase(y);
                friends[y].erase(x);
                if(x>y){
                    if(friends[y].upper_bound(y)==friends[y].end())
                        survivors.insert(y); 
                }else{
                    if(friends[x].upper_bound(x)==friends[x].end())
                        survivors.insert(x);
                }              
            }else{
                friends[x].insert(y);
                friends[y].insert(x);
                if(x>y){
                    survivors.erase(y);
                }else{
                    survivors.erase(x);
                }
            }
        }
    }
    
    return 0;
}