#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct regiao
{
    ll lb, ub, area;
    regiao(ll _lb, ll _ub, ll _area)
    {
        lb = _lb;
        ub = _ub;
        area = _area;
    }
    regiao();
};

bool ordenar(regiao a, regiao b)
{
    return a.lb > b.lb;
}

ll regiao_abaixo(ll linha, regiao a)
{
    if (linha > a.lb)
    {
        if (linha >= a.ub)
        {
            return a.area;
        }
        else
        {
            return (linha - a.lb) * (a.area / (a.ub - a.lb));
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    ll n, x0, x1, y0, y1, taxa, total = 0;
    vector<regiao> v;
    cin >> n >> taxa;
    for (int i = 0; i < n; i++)
    {
        cin >> x0 >> y0 >> x1 >> y1;
        v.push_back(regiao(y0, y1, ((y1 - y0) * (x1 - x0))));
        total += v.back().area;
    }

    if (total < taxa)
    {
        cout << "PERDAO MEU REI" << endl;
    }
    else
    {
        ll meio=0, cima = 10e+9, baixo = -10e+9;
        while (cima != baixo)
        {
            meio = (cima + baixo) / 2;
            ll abaixo = 0;
            for (auto x : v)
            {
                abaixo += regiao_abaixo(meio, x);
            }
            if (abaixo > taxa)
                cima = meio - 1;
            else if (abaixo < taxa)
                baixo = meio + 1;
            else{
                cima=baixo=meio;
            } 
        }
        cout<<cima<<endl;
    }

    return 0;
}