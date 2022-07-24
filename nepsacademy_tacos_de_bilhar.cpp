#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cont=0, a ;
    set<int> tacos;
    cin>>n;
    while(n--){
        cin>>a;
        auto ptr=tacos.find(a);
        if(ptr==tacos.end()){
            tacos.insert(a);
            cont+=2;
        }else{
            tacos.erase(ptr);
        }
    }
    cout<<cont<<endl;

    return 0;
}