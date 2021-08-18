#include <bits/stdc++.h>
#define LL long long
#define LIM 1000000
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int v[8] = {0};
    for(auto &it: v){
        it = LIM;
    }
    while(n--){
        int p;
        string s;
        cin>>p>>s;
        int bm = 0;
        for(auto it : s){
           bm += 1 << it-'a'; 
        }
        v[bm] = min(v[bm],p);
    }

    int ans = min(v[7],
                min(v[1]+v[2]+v[4], 
                    min(v[1]+v[6],
                        min(v[2]+v[5],
                            min(v[4]+v[3],
                                min(v[3]+v[5],
                                    min(v[3]+v[6],v[5]+v[6])
                                )
                            )
                        )
                    )
                )
            );
    if(ans>=LIM)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}