#include <bits/stdc++.h>
using namespace std;
int p,a,b;
int rec(int l, int r, int n){
    if(a<l or r<b)
        return n;
    int m=(l+r)/2;
    return min(rec(l,m,n-1),rec(m+1,r,n-1));
}
int main(){
    while(cin>>p>>a>>b){
        if(b<a){
            swap(a,b);
        }
        cout<<rec(1,1<<p,p)+1<<endl;
    }
}