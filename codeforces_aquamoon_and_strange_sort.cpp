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
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define PB push_back
#define PI pair<int,int>
#define F first
#define S second
#define N 100000
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int arr[LIM];
    int t;
    cin >> t;
    while(t--){
        int n;
        map<int,int> odd, even;
        cin>>n;
        
        FOR(0,n){
            cin >> arr[I];
        
            if(I%2)
                odd[arr[I]]++;
            else
                even[arr[I]]++;
        }
        sort(arr,arr+n);
        
        FOR(0,n)
            if(I%2)
                odd[arr[I]]--;
            else
                even[arr[I]]--;
        
        bool flag = true;
        
        FORIT(even)
            if(IT.S != 0)
                flag = false;

        FORIT(odd)
            if(IT.S != 0)
                flag = false;

        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}