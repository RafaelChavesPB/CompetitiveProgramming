#include <bits/stdc++.h>
#define pi pair<int, int>
#define f first
#define s second

using namespace std;

int main()
{
    int cont = 1, n, a, b;
    map<int,vector<int>> lista;
    while (cin >> n, n)
    {
        int maior=0;
        lista.clear();
        while (n--)
        {
            cin >> a >> b;
            lista[b].push_back(a);
            maior=max(maior,b);
        }
        cout << "Turma " << cont++ << endl;
        
        for(auto x: lista[maior]){
            cout<<x<<' ';
        }
        cout<<endl<<endl;
    }

    return 0;
}