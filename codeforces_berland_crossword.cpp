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

typedef struct Line{
    int prv;
    int mid;
    int left;

    void printall(){
        cout<<left<<' '<<mid<<' '<<prv<<endl;
    }
    
    void print(){
        cout<<left<<' ';
    }
} line;

bool rec(vector<line> arr, int it, int all_left){
    if(it == 8){
        return !all_left; 
    }
    
    int p = it % 4;
    int prv = (p + 4 - 1) % 4;

    bool flag = rec(arr,it+1,all_left);
    if(arr[p].left > 0){
        if(arr[p].mid){
            arr[p].mid--;
            arr[p].left--;
            flag = flag or rec(arr, it + 1, all_left-1);
            arr[p].mid++;
            arr[p].left++;
        }
        if(arr[p].prv and arr[prv].left){
            arr[prv].left--;
            arr[p].left--;
            arr[p].prv--;
            flag = flag or rec(arr, it + 1, all_left-2);
            arr[prv].left++;
            arr[p].left++;
            arr[p].prv++;
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>> t;
    while(t--){
        int n,v;
        cin>>n;
        vector<line> arr;
        int acc = 0;
        FOR(0,4){
            cin>>v;
            int left = min(2,v);  
            acc += left;
            int painted = (v - left);
            int mid = n - 2 - painted;
            arr.push_back({1,mid,left});
        }
        cout<<(rec(arr,0,acc)?"YES":"NO")<<endl;
    }
    return 0;
}