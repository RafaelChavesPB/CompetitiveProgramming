#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int a, b, c, ans = 0, time = 420;
        queue<pair<int, int>> fila;
        while (n--)
        {
            cin >> a >> b >> c;
            fila.push({a * 60 + b, c});
        }
        int inicio = 420;
        while (!fila.empty())
        {
            auto atual = fila.front();
            fila.pop();
            if (inicio < atual.first)
            {
                if (atual.first % 30)
                    inicio = atual.first - (atual.first % 30) + 30;
            }
            else if (inicio > atual.first + atual.second)
            {
                ans++;
            }
            inicio += 30;
        }
        cout << ans << endl;
    }
    return 0;
}