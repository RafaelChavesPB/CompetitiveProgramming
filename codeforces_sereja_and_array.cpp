#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, op, x, y, q, v, total=0;
    cin >> n >> m;
    vector<int> lista(n + 1);
    vector<int> ajuste(n + 1,0);
    for(int i = 1; i <= n; i++)
        cin >> lista[i];
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == 1){
            cin >> v >> x;
            ajuste[v] = x - lista[v] - total; 
        }else if(op == 2){
            cin >> y;
            total += y;
        }else{
            cin >> q;
            cout << lista[q] + total + ajuste[q] << endl;
        }
    }
    return 0;
}