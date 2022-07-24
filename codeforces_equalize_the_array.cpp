//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
    #define bugM(X,N,M) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define LLMAX 123456789012345
#define LLMIN -123456789012345
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 200001
#define MOD 1'000'000'007
using namespace std;


//Soma de todas as posições com indice menor igual a I
void prefixSum(LL arr[], LL prefix[], int n){
    prefix[0] = 0;

    FOR(1,n+1)
        prefix[I] = prefix[I-1] + arr[I];
    
}

void prefixSumAlt(LL arr[], LL prefix[], int n){
    prefix[0] = 0;

    FOR(1,n+1)
        prefix[I] = prefix[I-1] + arr[I]*I;
    
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL t;
    LL prefix_freq[LIM], prefix_nums[LIM], ocurr[LIM];
    map<int,int> freq;
    cin >> t;
    while(t--){
        int n, temp;
        cin >> n;
        
        FOR(0,n+1){
            ocurr[I] = 0; 
            freq[I] = 0;
        }

        FOR(0, n){
            cin >> temp;
            freq[temp]++;
        }

        FORIT(freq)
            ocurr[IT.S]++;
        
        prefixSum(ocurr, prefix_freq, n);
        prefixSumAlt(ocurr, prefix_nums, n);
        
        freq.clear();

        LL ans = MAX;
        FOR(1,n+1)
            ans = min(ans, prefix_nums[I-1] + (prefix_nums[n] - prefix_nums[I]) - (prefix_freq[n] - prefix_freq[I]) * I);
        
        cout<< ans << endl;
    }
    return 0;
}

//Soma de todas a posições com indice estritamente maior a I
// void suffixSum(int arr[], int suffix[], int n){
//     suffix[n] = 0;

//     FORR(n, 0)
//         suffix[R] = suffix[R+1] + arr[R+1];
// }
