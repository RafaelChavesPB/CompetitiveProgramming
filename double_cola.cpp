//Problema disponível em: https://codeforces.com/problemset/problem/82/A
#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define F first
#define S second

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pl> a,b,c,d,e; 
    for(ll i = 0, p = 1; p<=n; i++){
        ll y = 1 << i;
        a.push_back({p,p+y-1});
        b.push_back({p+y,p+2*y-1});
        c.push_back({p+2*y,p+3*y-1});
        d.push_back({p+3*y,p+4*y-1});
        e.push_back({p+4*y,p+5*y-1});
        p += 5*y;
    }
    for(int i=0;i<a.size();i++){
        if(a[i].F<= n and n <= a[i].S ){
            cout<<"Sheldon"<<endl;
            return 0;
        }else if(b[i].F<= n and n <= b[i].S){
            cout<<"Leonard"<<endl;
            return 0;
        }else if(c[i].F<= n and n <= c[i].S){
            cout<<"Penny"<<endl;
            return 0;
        }else if(d[i].F<= n and n <= d[i].S){
            cout<<"Rajesh"<<endl;
            return 0;
        }else if(e[i].F<= n and n <= e[i].S){
            cout<<"Howard"<<endl;
            return 0;
        }
    }
    return 0;
}