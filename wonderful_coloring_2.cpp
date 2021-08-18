#include <bits/stdc++.h>
#define DEBUG 
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
#else
    #define bug(X) {;}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,temp;
        cin>>n>>k;
        map<int,vector<int>> freq;
        queue<int> fila;
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>temp;
            if(freq[temp].size()<k)
                freq[temp].push_back(i);
        }
        for(auto it : freq){
            if(it.second.size()==k){
                for(int i=0;i<k;i++){
                    ans[it.second[i]]=i+1;
                }
            }else{
                for(int i=0;i<it.second.size();i++){
                    fila.push(it.second[i]);
                    if(fila.size()==k){
                        for(int j=1;j<=k;j++){
                            ans[fila.front()] = j;
                            fila.pop();
                        }
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;


    }
    return 0;
}