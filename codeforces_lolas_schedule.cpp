//Disponível em: https://codeforces.com/gym/103185
#include <bits/stdc++.h>
#define pi pair<int,int>
#define F first
#define S second

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<pi> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].F>>v[i].S;
    }
    pi best(INT_MAX,INT_MAX);
    for(int t = 0; t <= 480; t++){
        int acc = 0;
        for(auto it: v){
            int d = it.F - t;
            if(d>=0){
                int mul = d/x + (d%x>0); 
                int e = x*mul + t;
                acc += (it.F <= e  and e <= it.F+it.S) * ((it.F+it.S-e)/x + 1);
            }else{
                acc += (d + it.S >= 0) * ((d+it.S)/x + 1);
            }
        }
        best = min(best,{acc,t});
    }
    cout<<best.S<<' '<<best.F<<endl;
    return 0;
}