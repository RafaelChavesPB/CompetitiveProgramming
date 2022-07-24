#include <bits/stdc++.h>
#define pi pair<int,int>
#define power first
#define weight second
using namespace std;

vector<pi> v;
int m[55][110];
int calcula(int pos,int peso){
    if(pos==v.size() or peso==0)
        return m[pos][peso]=0;
    if(m[pos][peso]!=-1)
        return m[pos][peso];
    if(v[pos].weight<=peso)
        return m[pos][peso]=max(calcula(pos+1,peso-v[pos].weight)+v[pos].power,calcula(pos+1, peso));
    return m[pos][peso]=calcula(pos+1,peso);
}

int main(){
    ios::sync_with_stdio(false);
    int cases, n, peso, protecao, ans;
    pi temp;
    cin>>cases;
    while(cases--){
        v.clear();
        memset(m,-1,sizeof(m));
        cin>>n;
        while(n--){
            cin>>temp.power>>temp.weight;
            v.push_back(temp);
        }
        cin>>peso>>protecao;
        ans=calcula(0,peso);
        if(ans>=protecao)
            cout<<"Missao completada com sucesso\n";
        else
            cout<<"Falha na missao\n";
        
    }
}