#include <bits/stdc++.h>

using namespace std;

vector<int> bit,v;
int n;

int sum(int index) {
    int soma = 0;
    while (index >= 1) {
        soma += bit[index];
        index -= index&-index;
    }
    return soma;
}

void update(int index, int dif) {
    while (index <= n){
        bit[index] += dif;
        index += index&-index;
    }
}

int main(){
    int m,a,b;
    string op;
    cin>>n>>m;
    v=bit=vector<int> (n+1,0);
    while(m--){
        cin>>op;
        if(op=="F"){
            cin>>a;
            if(v[a]){
                b=-1;
            }else{
                b=1;
            }
            v[a]=1-v[a];
            update(a,b);
        }else{
            cin>>a>>b;
            cout<<sum(b)-sum(a-1)<<endl;
        }
    }

}
