#include <bits/stdc++.h>
#define LIM 100000
using namespace std;

vector<vector<int>> st(4 * LIM);
vector<int> cont(LIM + 1);

int func(int v){
    if(v>=8){
        return 8;
    }else if(v>=6){
        return 6;
    }else if(v>=4)
        return 4;
    else if(v>=2)
        return 2;
    else 
        return 0;
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        st[node]={cont[l],0,0};
        return;
    }
    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
    vector<int> temp(6);
    merge(st[2 * node + 1].begin(), st[2 * node + 1].end(), st[2 * node].begin(), st[2 * node].end(), temp.begin(),  greater<int>());
    st[node].assign(temp.begin(), temp.begin() + 3);
}

void update(int node, int l, int r, int length, int diff)
{
    if (l == r)
    {
        st[node][0] += diff;
        return;
    }
    int m = (l + r) / 2;
    if (length <= m)
        update(2 * node, l, m, length, diff);
    else
        update(2 * node + 1, m + 1, r, length, diff);
    vector<int> temp(6);
    merge(st[2 * node + 1].begin(), st[2 * node + 1].end(), st[2 * node].begin(), st[2 * node].end(), temp.begin(), greater<int>());
    st[node].assign(temp.begin(), temp.begin() + 3);
    return;
}

int main()
{
    int n, m, length;
    string op;
    cin >> n;
    while (n--)
    {
        cin >> length;
        cont[length]++;
    }
    build(1, 1, LIM);
    cin >> m;
    while (m--)
    {
        cin >> op >> length;
        update(1, 1, LIM, length, (op == "+" ? 1 : -1));
        int soma = func(st[1][0]) + func(st[1][1]) + func(st[1][2]);
        if(soma>=8){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}