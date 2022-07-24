#include <bits/stdc++.h>
using namespace std;
struct food
{
    long long needed, owned, price;
    food(int n, int o, int p)
    {
        needed = n;
        owned = o;
        price = p;
    }
};

long long cost(food a, long long q){
    q*=a.needed;
    q -= min(q,a.owned);
    return q*a.price;
}

vector<food> ham;
long long r;

long long bs(long long s, long long e){
    if(s>e)
        return 0;
    long long m = (s+e)/2;
    long long value=0;
    for(auto x: ham)
        value+=cost(x,m);
    if(value<=r)
        return max(m,bs(m+1,e));
    else
        return bs(s,m-1);
}

int main()
{
    string in;
    long long nb=0, ns=0, nc=0, ob, os, oc, pb, ps, pc;
    cin>>in;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == 'B')
            nb++;
        else if (in[i] == 'S')
            ns++;
        else
            nc++;
    }
    cin >> ob >> os >> oc >> pb >> ps >> pc >> r;
    if (nb!=0)
        ham.push_back(food(nb, ob, pb));
    if (ns!=0)
        ham.push_back(food(ns, os, ps));
    if (nc!=0)
        ham.push_back(food(nc, oc, pc));
    cout<<bs(1,10000000000000)<<endl;
    return 0;
} 