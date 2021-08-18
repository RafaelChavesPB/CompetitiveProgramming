//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORK(S,E) for(int k = S; k < E; k++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 50001
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int grid[LIM][5];
    int ans[LIM];
    int t;
    cin>>t;     
    while(t--){
        int n;
        cin>>n;
        FOR(0,n){
            FORJ(0,5)
                cin>>grid[i][j];
            ans[i] = 1;
        }
        FOR(0,n){
            if(ans[i]){
                FORJ(0,n){
                    if(i!=j){
                        int a = 0, b = 0;
                        FORK(0,5){
                            a += grid[i][k]<grid[j][k];
                            b += grid[j][k]<grid[i][k];
                        }
                        if(b<3){
                            ans[j] = 0;
                        }
                        if(a<3){
                            ans[i] = 0;
                            break;
                        }    
                    }
                }
            }       
        }
        bugV(ans,n);
        bool flag = false;
        FOR(0,n){
            if(ans[i]){
                cout<<i+1<<endl;
                flag = true;
                break;
            }
        }

        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}