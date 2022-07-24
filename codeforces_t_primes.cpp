#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> crivo(int n) {
    vector<int> primos;
    vector<bool> v(n+1, true);
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            primos.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
    return primos;
}
int main() {
    int n;
    ll x;
    auto p = crivo(10e+6);
    cin >> n;
    while (n--){
        string ans = "NO";
        cin >> x;
        ll raiz = sqrt(x);
        if (raiz * raiz == x  and binary_search(p.begin(), p.end(),raiz)){
            ans = "YES";
        }
        cout << ans << endl;
    } 
    return 0;
}