#include <bits/stdc++.h>
#define pi pair<int,int>
#define price first
#define weight second

using namespace std;

vector<pi> v;

int m[110][1010];
int calcula(int pos,int peso){
    if(pos==v.size() or peso==0)
        return m[pos][peso]=0;
    if(m[pos][peso]!=-1)
        return m[pos][peso];
    if(peso>=v[pos].weight)
        return m[pos][peso]=max(calcula(pos+1,peso-v[pos].weight)+v[pos].price,calcula(pos+1,peso));
    return m[pos][peso]=calcula(pos+1,peso);
}


int main(){
    int n, peso, ans;
    pi temp;
    while(scanf("%d",&n)&&n){
        memset(m,-1,sizeof(m));
        v.clear();
        while(n--){
            scanf("%d %d", &temp.price,&temp.weight);
            v.push_back(temp);
        }
        scanf("%d",&peso);
        ans=calcula(0,peso);
        printf("%d\n",ans);
    }


}