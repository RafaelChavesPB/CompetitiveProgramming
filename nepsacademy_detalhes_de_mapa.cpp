#include <bits/stdc++.h>

using namespace std;

struct aresta
{
    int x, y, peso;
};

bool comp(aresta a, aresta b)
{
    return a.peso < b.peso;
}

vector<aresta> a;
vector<int> pai(501);
vector<int> peso(501);

int find(int x)
{
    if (pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if (peso[a] < peso[b])
        pai[a] = b;
    else if (peso[b] < peso[a])
        pai[b] = a;
    else
    {
        pai[a] = b;
        peso[b]++;
    }
}

int main()
{
    int m, n, ans = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        a.push_back(aresta());
        cin >> a.back().x >> a.back().y >> a.back().peso;
    }
    for (int i = 1; i <= n; i++){
        pai[i]=i;
    }

    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < m; i++){
        if (find(a[i].x) != find(a[i].y)){
            join(a[i].x, a[i].y);
        }
    }
    return 0;
}