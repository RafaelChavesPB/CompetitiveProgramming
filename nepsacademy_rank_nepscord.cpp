#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{

    int n, k, m;
    string nome;
    vector<pair<string, int>> podio(3, make_pair("", 0));
    map<string, pair<int, int>> lista;
    cin >> n >> k;
    while (n--)
    {
        cin >> nome >> m;
        if (lista.find(nome) == lista.end())
        {
            lista[nome] = make_pair(m, 25);
        }
        else
        {
            if (m >= lista[nome].f + k)
            {
                lista[nome].f = m;
                lista[nome].s += 25;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        string melhor;
        int p_melhor = -1;
        for (auto it : lista)
        {
            if (it.s.s > p_melhor)
            {
                melhor = it.first;
                p_melhor = it.s.s;
            }
        }
        podio[i] = make_pair(melhor, p_melhor);
        lista.erase(melhor);
    }
    cout<<"--Rank do Nepscord--"<<endl;
    int a=1;
    for(auto v: podio){
        cout<<"#"<<a++<<".";
        if(v.f!="")
            cout<<" "<<v.f<<" - "<<"Nivel "<<(v.s/100)+1;
        cout<<endl;
    }
}