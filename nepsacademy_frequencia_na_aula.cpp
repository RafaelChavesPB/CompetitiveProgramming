#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> lista;
    int n,a;

    cin>>n;
    while(n--){
        cin>>a;
        lista.insert(a);
    }
    cout<<lista.size()<<endl;


    return 0;
}