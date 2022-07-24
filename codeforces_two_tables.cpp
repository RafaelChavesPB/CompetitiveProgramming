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
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cout<<fixed<<setprecision(7);
    FOR(0,t){
        int W,H,w2,h2,w1,h1,x1,x2,y1,y2, moves_needed=0;
        int DX, DY, MX, MY, ans = INT_MAX;
        cin>>W>>H;
        cin>>x1>>y1>>x2>>y2;
        w1 = x2-x1;
        h1 = y2-y1;
        cin>>w2>>h2;
        int TW = w1 + w2;
        int TH = h1 + h2;
        if(TW>W and TH>H){
            cout<<-1<<endl;
            continue;
        }
        
        if(TH>H){
            DX = max(x1,W-x2);
            MX = max(0,w2-DX);
            cout<<(double)MX<<endl;
            continue;
        }

        if(TW>W){
            DY = max(y1,H-y2);
            MY = max(0,h2-DY);
            cout<<(double)MY<<endl;
            continue;
        }
        DX = max(x1,W-x2);
        MX = max(0,w2-DX);
        DY = max(y1,H-y2);
        MY = max(0,h2-DY);
        cout<<(double)min(MY,MX)<<endl;
    }
    return 0;
}