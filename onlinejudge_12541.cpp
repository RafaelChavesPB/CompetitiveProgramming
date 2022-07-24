#include <bits/stdc++.h>
#define pis pair<int,string>
#define pii pair<int,int>
#define p pair<pii,pis>
#define f first
#define s second
 
using namespace std;
int main(){
    int n;
    vector<p> v;
    string a;
    int b,c,d;
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d;
        v.push_back({{d,c},{b,a}});
    }
    sort(v.begin(),v.end());
    cout<<v.back().s.s<<endl;
    cout<<v.front().s.s<<endl;
}