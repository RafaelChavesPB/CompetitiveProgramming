#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool func(ll n){
    if(n==2){
        return true;
    }
    for(int i=2;i<=sqrt(n+1);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    ll n;
    while (cin >> n, n)
    {
        int i = 2*n + 1;
        while (!func(i))
        {
            i++;
        }
        cout << i;
        if (!func(n))
        {
            cout<<" ("<<n<<" is not prime)";
        }
        cout<<endl;
    }

    return 0;
}