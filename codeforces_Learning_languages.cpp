#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> lang_emp;
vector<vector<int>> emp_lang;
vector<int> cc;

void dfs(int c, int e){
    cc[e]=c;
    for(auto l: emp_lang[e]){
        for(auto x: lang_emp[l]){
            if(!cc[x])
                dfs(c,x);
        }
    }
}
int main(){
    int n,m,k,a;
    bool any_language = false;
    cin>>n>>m;
    lang_emp.resize(m+1);
    emp_lang.resize(n+1);
    cc.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            any_language = true;
            cin>>a;
            lang_emp[a].push_back(i);
            emp_lang[i].push_back(a);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!cc[i]){
            dfs(++ans,i);
        }
    }
    cout<<ans-any_language<<endl;
    return 0;
}