#include <bits/stdc++.h>
using namespace std;

deque<int> crivo(int n, size_t qtd) {
    deque<int> primos;
    vector<bool> v(n + 1, true);
    for (long long i = 2; i <= n; i++) {
        if (v[i]) {
            if(primos.size()==qtd)
                break;
            else
                primos.push_back(i);
            for (long long j = i * i; j <= n; j += i)
                v[j]=false;
        }
    }
    return primos;
}

int main(){
    int n;
    cin>>n;
    auto primos = crivo(10000000, n);
    for(auto x : primos){
        cout<<x<<' ';
    }
    cout<<endl;

    return 0;
}