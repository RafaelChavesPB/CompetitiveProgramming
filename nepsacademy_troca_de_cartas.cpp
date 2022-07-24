#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,a, cont_a=0, cont_b=0;
    set<int> alice, r_alice, beatriz, r_beatriz;

    cin>>n>>m;

    while(n--){
        cin>>a;
         alice.insert(a);
    }

    while(m--){
        cin>>a;
        beatriz.insert(a);
    }

    for(auto i: alice){
        if(beatriz.find(i)==beatriz.end()){
            cont_a++;
        }
    }

    for(auto i: beatriz){
        if(alice.find(i)==alice.end()){
            cont_b++;
        }
    }

    cout<<min(cont_a,cont_b)<<endl;
    return 0;
}