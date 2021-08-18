#include <bits/stdc++.h>
#define LL long long
#define LIM 500
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif

using namespace std;

vector<string> arr(500);
int pd[500][500];
LL ans; 
int n,m;

int rec(int i, int j){
    if(i<0 or i == n or j<0 or j==m)
        return 0;
    if(arr[i][j]=='.')
        return 0;
    if(pd[i][j]!=-1)
        return pd[i][j];
    int height = min(rec(i+1,j+1),min(rec(i+1,j),rec(i+1,j-1))) + 1;
    ans+=height;
    return pd[i][j] = height;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            for(int j=0;j<m;j++){
                pd[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rec(i,j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}