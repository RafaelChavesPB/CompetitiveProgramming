#include <bits/stdc++.h>

using namespace std;

struct st_aresta
{
    int x, y, peso, tipo;
};

vector<int> pai(101), peso(101, 0);

int find(int x)
{
    if (pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);

    if (peso[x] < peso[y])
        pai[x] = y;
    else
    {
        if (peso[y] < peso[x])
            pai[y] = x;
        else
        {
            pai[x] = y;
            peso[y]++;
        }
    }
}

bool comp(st_aresta a, st_aresta b)
{
    if (a.tipo != b.tipo)
        return a.tipo < b.tipo;
    return a.peso < b.peso;
}

vector<st_aresta> a;

int main()
{
    int n, f, r, ans = 0;

    cin >> n >> f >> r;

    for (int i = 0; i < f; i++)
    {
        a.push_back(st_aresta());
        cin >> a.back().x >> a.back().y >> a.back().peso;
        a.back().tipo = 0;
    }
    for (int i = 0; i < r; i++)
    {
        a.push_back(st_aresta());
        cin >> a.back().x >> a.back().y >> a.back().peso;
        a.back().tipo = 1;
    }

    for (int i = 1; i <= n; i++)
        pai[i] = i;

    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < a.size(); i++)
    {
        if (find(a[i].x) != find(a[i].y))
        {
            join(a[i].x, a[i].y);
            ans += a[i].peso;
        }
    }

    cout << ans << endl;
    return 0;
}