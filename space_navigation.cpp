//cp template.cpp space_navigation.cpp && code space_navigation.cpp
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int x, y, u = 0, d = 0, r = 0 , l = 0;
        string s;
        cin>>x>>y;
        cin>>s;
        FOR(0,s.size())
            if(s[i]=='R')
                r++;
            else if(s[i]=='D')
                d++;
            else if(s[i]=='L')
                l++;
            else 
                u++;
        
        bool flag = true;
        
        if(x < 0)
            flag = flag and abs(x) <= l;
        else
            flag = flag and x <= r;
        

        if(y < 0) flag = flag and abs(y) <= d;
        else flag = flag and y <= u;
        cout<<(flag?"YES":"NO")<<endl;
    }
    
    return 0;
}