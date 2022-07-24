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
#define F first
#define S second
#define LIM 100001
using namespace std;

typedef struct Balde{
    int l;
    int r;
    vector<LL> sat; 
}balde;

struct sqrtdec{
    int size; //quprvidade de baldes
    int bs; //tamanho do balde
    vector<balde> B; //vetor com os baldes

    sqrtdec(vector<LL> &arr, int n){
        bs = sqrt(n);
        size = n / bs + (n % bs > 0);
        B.resize(size);
        for(int i = 0; i < size; i++){
            B[i].l = i * bs;
            B[i].r = min((i + 1) * bs - 1, n - 1);
            B[i].sat.resize(bs);
            for(int j = B[i].l, k = 0; j <= B[i].r; j++, k++){
                B[i].sat[k] = arr[j];
            }
            sort(B[i].sat.begin(),B[i].sat.end());
        }
    }

    void update(LL prv, int id, LL nval){
        int i = id/bs;
        int j = lower_bound(B[i].sat.begin(), B[i].sat.end(), prv) - B[i].sat.begin();

        B[i].sat[j] = nval;

        if(prv < nval){
            while(j < bs-1 and nval > B[i].sat[j+1]){
                swap(B[i].sat[j],B[i].sat[j+1]);
                j++;
            }
        }else if(prv > nval){
            while(j > 0 and nval < B[i].sat[j-1]){
                swap(B[i].sat[j],B[i].sat[j-1]);
                j--;
            }
        }
    }

    long long query(vector<LL> &arr, int ql, int qr, LL value){
        int hb = ql / bs;
        int tb = qr / bs;
        long long ans = 0; 
        for(int i = ql; i <= min(B[hb].r, qr); i++){
            ans += arr[i]<value;
            bug(arr[i]);
            bug(value);
        } //cabeça
        
        if(hb != tb){
            for(int i = max(B[tb].l, ql); i <= qr; i++) //cauda
                ans += arr[i]<value;
            for(int i = hb + 1; i < tb; i++){
                ans += lower_bound(B[i].sat.begin(),B[i].sat.end(),value) - B[i].sat.begin();

            } //bucho

        }
        return ans;
    }
};

bool fastscan(int &number){
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    while(c == 32 or c == EOF or c == 10 or c=='\r'){
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
    int n, m, u;
    while(fastscan(n)){
        int l, r, v, p, k;
        vector<LL> arr(n);
        LL nval,prv;
        fastscan(m);
        fastscan(u);
        FOR(0,n){
            int temp;
            fastscan(temp);
            arr[i] = temp;
        }
        sqrtdec sq(arr,n);
        while(m--){
            fastscan(l);
            fastscan(r);
            fastscan(v);
            fastscan(p);
            l--,r--,p--;
            k = sq.query(arr,l,r,v);
            bug(k);
            nval =  1LL*u*k/(r-l+1LL);
            bug(nval);
            prv = arr[p];
            arr[p] = nval;
            sq.update(prv,p,nval);
        }
        FOR(0,n){
            printf("%lld\n",arr[i]);
        }
    }
    
    return 0;
}

