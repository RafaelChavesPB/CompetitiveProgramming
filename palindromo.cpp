#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<string> a;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string x;
        cin >> x;
        a.push_back(x);
    }
    map<long long, int> afc;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        // cout << a[i] << " -> ";
        long long mask = 0;
        for(int j = 0; j < (int)a[i].size(); j++){
            mask ^= (1 << a[i][j]-'a');
        }
        // for(auto x: cont)
        //     cout << x << " ";
        ans += afc[mask];
        for(int j = 0; j < 27; j++){
            ans += afc[mask ^ (1 << j)];
        }
        afc[mask]++;
    }
    cout << ans <<"\n";

    return 0;
}