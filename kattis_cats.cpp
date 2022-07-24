#include <bits/stdc++.h>

using namespace std;

struct aresta
{
    int x, y, dist;
};

vector<aresta> a;
vector<int> pai;
vector<int> peso;

bool compare(aresta b, aresta c)
{
    return b.dist < c.dist;
}
int find(int x)
{
    if (pai[x] == x)
    {
        return x;
    }
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (peso[a] < peso[b])
    {
        pai[a] = b;
    }
    else if (peso[a] > peso[b])
    {
        pai[b] = a;
    }
    else
    {
        pai[a] = b;
        peso[b]++;
    }
}

int kruskal(int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        pai[i] = i;
    }
    sort(a.begin(), a.end(), compare);
    for (auto it : a)
    {
        if (find(it.x) != find(it.y))
        {
            join(it.x, it.y);
            ans += it.dist;
        }
    }
    return ans;
}
int main()
{
    int t, n, m, lim;
    cin >> t;
    while (t--)
    {
        cin >> lim >> n;
        pai = vector<int>(n);
        peso = vector<int>(n, 0);
        a = vector<aresta>();
        m = (n * (n - 1)) / 2;
        while (m--)
        {
            a.push_back(aresta());
            cin >> a.back().x >> a.back().y >> a.back().dist;
        }
        int ans = kruskal(n)+n;
        cout << (lim >= ans ? "yes\n" : "no\n");
    }
    return 0;
}