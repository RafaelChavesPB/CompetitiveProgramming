#include <bits/stdc++.h>
#define pi pair<int,int>
#define vpi vector<pi>
#define vi vector<int>
#define w second
#define p first
#define QPOS 1001
#define WPOSSIVEIS 31
using namespace std;

vpi prod;
vi pessoa;
int memory[QPOS][WPOSSIVEIS];

int totalpower(int pos, int weight){
    int valor=0;
    if(pos==prod.size()){
        return 0;
    }
    if(memory[pos][weight]){
        return memory[pos][weight];
    }
    if(prod[pos].w<=weight){
        valor=totalpower(pos+1, weight-prod[pos].w)+prod[pos].p;
    }

    valor=max(valor,totalpower(pos+1,weight));
    memory[pos][weight]=valor;
    return valor;
}

int main(){
    ios::sync_with_stdio(false);
    int n,cases, temp2, total;
    pi temp;
    cin>>cases;

    while(cases--){
        total=0;
        cin>>n;

        while(n--){
            cin>>temp.p>>temp.w;
            prod.push_back(temp);
        }

        cin>>n;

        while(n--){
            cin>>temp2;
            pessoa.push_back(temp2);
        }

        for(auto x:pessoa){
            total+=totalpower(0,x);
        }

        cout<<total<<"\n";
        pessoa.clear();
        prod.clear();

        for(int i=0;i<QPOS;i++){
            for(int j=0;j<WPOSSIVEIS;j++){
                memory[i][j]=0;
            }
        }
    }
        
    return 0;
}