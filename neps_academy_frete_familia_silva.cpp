#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int n, m;
vector<int> custo(1001,98765432);
vector<bool> visitado(1001, 0);
vector<vector<ii>> lista(1001);
priority_queue<ii, vector<ii>, greater<ii>> fila;

int prim()
{
    fila.push(ii(0, 0));
    custo[0]=0;
    while (true)
    {
        int davez = -1;
        while (!fila.empty())
        {
            int atual = fila.top().second;
            fila.pop();

            if (!visitado[atual])
            {
                davez = atual;
                break;
            }
        }

        if (davez == -1)
            break;

        visitado[davez]=true;

        for(auto x: lista[davez]){
            int peso=x.first;
            int v=x.second;

            if(custo[v]>peso and !visitado[v]){
                fila.push(ii(peso,v));
                custo[v]=peso;
            }
        }
    }

    int ans=0;

    for(int i=0; i<n;i++){
        ans+=custo[i];
    }
    return ans;
}

int main()
{
    int v1, v2, peso;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> peso;
        lista[v1].push_back(ii(peso, v2));
        lista[v2].push_back(ii(peso, v1));
    }
    auto a= prim();

    cout << a << endl;

    return 0;
}