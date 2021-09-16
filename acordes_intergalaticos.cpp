//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int z = 0; z < N; z++ ) cout<< X[z] <<' ';  cout<<endl; }
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

typedef struct Balde{
    int l;
    int r;
    char lua;
    vector<int> sat;
}balde;

struct sqrtdec{
    int size; //quantidade de baldes
    int bs; //tamanho do balde
    vector<balde> B; //vetor com os baldes

    sqrtdec(int n){
        bs = 2*sqrt(n);
        size = n / bs + (n % bs > 0);
        B.resize(size);
        for(int i = 0; i < size; i++){
            int left, right;
            left = i * bs;
            right = min((i + 1) * bs - 1, n - 1);
            B[i] = {left, right, 0, {0, bs, 0, 0, 0, 0, 0, 0, 0}};
        }
    }

    void update(vector<char> &arr, char nval, int ql, int qr){
        int hb = ql / bs;
        int tb = qr / bs;
        atualiza_balde(arr,hb);
        for(int i = ql; i <= min(B[hb].r, qr); i++){
            B[hb].sat[arr[i]]--;
            arr[i] = (arr[i] + nval)%9;
            B[hb].sat[arr[i]]++;
        }
        
        if(hb != tb){
            atualiza_balde(arr,tb);
            for(int i = max(B[tb].l, ql); i <= qr; i++){
                B[tb].sat[arr[i]]--;
                arr[i] = (arr[i] + nval)%9;
                B[tb].sat[arr[i]]++;
            } 
        }
        
        for(int i = hb + 1; i < tb; i++)
            B[i].lua = (B[i].lua + nval) % 9;
        
    }

    void atualiza_balde(vector<char> &arr, int b){
        if(B[b].lua){
            char lua = B[b].lua; 
            for(int i = B[b].l; i <= B[b].r; i++)
                arr[i] = (arr[i] + lua) % 9; 
            
            vector<int> aux = B[b].sat;
            for(int i = 0; i < 9; i++)
                B[b].sat[(i + lua)%9] = aux[i];
        }
        B[b].lua = 0;
    }

    int query(vector<char> &arr, int ql, int qr){
        int hb = ql / bs;
        int tb = qr / bs;
        vector<int> ans(9, 0); 

        for(int i = ql; i <= min(B[hb].r, qr); i++)
            ans[(arr[i]+B[hb].lua)%9]++;
        
        if(hb != tb){ 
            for(int i = max(B[tb].l, ql); i <= qr; i++) 
                ans[(arr[i]+B[tb].lua)%9]++;
            
            for(int i = hb + 1; i < tb; i++){
                for(int j = 0; j <= 8; j++)
                    ans[(j + B[i].lua)%9] += B[i].sat[j]; 
            }
   
        }
        
        pair<int, int> best = {-1, -1};
        for(int i = 0; i <= 8; i++){
            best = max(make_pair(ans[i], i), best);
        }
        return best.second;
    }
};

bool fastscan(int &number){
	bool negative = false;
	int c;
	number = 0;
    c = getchar();
    while(c == 32 or c == EOF or c == 10 or c == '\r'){
        c = getchar();
        if(c == EOF){
            return false;
        }
    }
	if(c == '-'){
		negative = true;
		c = getchar();
	}
	for(; (c>47 && c<58); c = getchar())
		number = number *10 + c - 48;
	if(negative)
		number *= -1;
    return true;
}

int main(){
    int n, q;
    fastscan(n);
    vector<char> arr(n, 1);
    fastscan(q);
    sqrtdec sq(n);
    while(q--){
        int a, b;
        fastscan(a);
        fastscan(b);
        int k = sq.query(arr, a, b);
        sq.update(arr, k, a, b);
    }
    FORJ(0,sq.size)
        sq.atualiza_balde(arr,j);    
    FOR(0,n)
        printf("%d\n", arr[i]);
        
    return 0;
}