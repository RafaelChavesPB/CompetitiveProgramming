#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    multiset<ll> v;
    ll n, temp, s, m, baixo, meio, cima;
    cin >> n >> m;
    while (n--)
    {
        cin >> temp;
        v.insert(temp);
    }

    baixo = *(v.end()--);
    cima = 10e+14;
    while (cima > baixo)
    {   
        auto faltando=v;
        int caixas=0;
        meio = (cima + baixo) / 2;
        while (!faltando.empty())
        {
            auto primeiro=faltando.begin();
            faltando.erase(primeiro);
            auto obj=meio-*primeiro;
            auto segundo=faltando.lower_bound(obj);
            caixas++;
            if(faltando.end()!=segundo ){
              if(*segundo>obj and segundo!=faltando.begin()){
                segundo--;
              }    
                faltando.erase(segundo);
            }
        }

        if(caixas<=m){
            cima=meio-1;
        }else{
            baixo=meio+1;
        }
    }
    cout<<meio<<endl;
    
    return 0;
}