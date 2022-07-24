#include <bits/stdc++.h>
#define lim 100000
using namespace std;

pair<long, long> fator(long n)
{
    long N = sqrt(n) + 1;
    pair<long, long> div(0, 0);
    for (long x = 2; x <= N; x++)
    {
        if (x == 2)
        {
            div.first = 1;
            while (n % 2 == 0)
            {
                div.first *= 2;
                n /= 2;
            }
        }
        else if (n % x == 0)
        {
            div.second = x;
            break;
        }
    }

    if (div.second == 0)
    {
        div.second = n;
    }
    return div;
}

int main()
{
    ios::sync_with_stdio(false);
    long qtd, n;
    cin >> qtd;

    while (qtd--)
    {
        cin >> n;
        if (n % 2 and n!=1)
        {
            cout << n << " = " << n / 2 << " + " << (n / 2) + 1 << endl;
        }
        else
        {
            auto div = fator(n);
            if (div.first == n or div.first==1)
            {
                cout << "IMPOSSIBLE" << endl;
            }
            else
            {
                if(div.first*2<div.second){
                    auto par=div.first;
                    auto impar=n/div.first;
                    auto flag=true;
                    for(int i=0;i<2*par;i++){
                        if(flag){
                            cout<<n<<" = ";
                            flag=false;
                        }else{
                            cout<<" + ";
                        }
                        cout<<(impar/2)-par+i+1;
                    }
                    cout<<endl;
                }else{
                    auto impar=div.second;
                    auto par=n/div.second;
                    auto flag=true;
                    for(int i=0;i<impar;i++){
                        if(flag){
                            cout<<n<<" = ";
                            flag=false;
                        }else{
                            cout<<" + ";
                        }
                        cout<<par-impar/2+i;
                    }
                    cout<<endl;
                }
            }
        }
    }

    return 0;
}