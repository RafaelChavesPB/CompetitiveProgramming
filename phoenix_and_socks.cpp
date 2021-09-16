//Problema Disponível em: 
#include <bits/stdc++.h>
#define submit
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        stack<int> a; 
        int n, l, r, temp, neg = 0, pos = 0, rest;
        int ans = 0;
        cin >> n >> l >> r;
        vector<int> freq(n+1,0);
        
        FOR(0,n){
            cin >> temp;
            if(I<l)
                freq[temp]++;
            else
                freq[temp]--;
        }

        FOR(1,n+1){
            if(freq[I]>0)
                pos+=freq[I];
            if(freq[I]<0)
                neg-=freq[I];
        }
        bugV(freq,n+1);
        int diff = abs(neg-pos);
        if(pos > neg){
            FOR(1,n+1){
                while(freq[I] > 1 and pos != neg){
                    pos-=2;
                    freq[I] -= 2;
                    ans += 1;
                }
            }
        }else if(neg > pos){
            FOR(1,n+1){
                while(freq[I] < -1 and pos != neg){
                    neg-=2;
                    freq[I] += 2;
                    ans += 1;
                }
            }
        }

        if(neg != pos){
            ans += max(neg,pos) - (neg+pos)/2;
        }
        ans += (neg + pos)/2; 

        cout << ans << endl;
    } 
    return 0;
}