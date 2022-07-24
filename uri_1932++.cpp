#include <bits/stdc++.h>
using namespace std;
int c;
int main()
{
    long long n, c,valor,v[2]={0,-12345678};
    cin >> n >> c;
    p.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> valor;
        v[0]=max(v[0],valor+v[1]-c);
        v[1]=max(v[0]-valor,v[1]);
    }
    cout<<v[0]<<endl;
    return 0;
}