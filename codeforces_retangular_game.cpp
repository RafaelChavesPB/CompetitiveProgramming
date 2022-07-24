//Problema disponivel em: https://codeforces.com/problemset/problem/177/B1
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, long long> mem;
long long rec(int n){
    if(n == 1)
        return 1;
    if(mem.find(n)!=mem.end())
        return mem[n];
    long long value = rec(1) + n;
    for(long long i=2;i<=sqrt(n);i++)
        if(n%i==0)
            value = max(value, max(rec(n/i)+n,rec(i)+n));
    return mem[n] = value;
}

int main(){
    int n;
    cin>>n;
    cout<<rec(n)<<endl;
    return 0;
}