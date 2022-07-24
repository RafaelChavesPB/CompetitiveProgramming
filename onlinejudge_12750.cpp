#include <bits/stdc++.h>
using namespace std;
pair<int,int> verify(vector<string> &v){
    int jogos=0;
    int jogos_sem_vitoria=0;
    for(auto x:v){
        jogos++;
        if(x!="W"){
            jogos_sem_vitoria++;
            if(jogos_sem_vitoria==3){
                return {jogos,false};
            }
        }else{
            jogos_sem_vitoria=0;
        }
    }
    return {jogos,true};
}
int main(){
    int t,n,cont=1;
    cin>>t;
    while(t--){
        cout<<"Case "<<cont++<<": ";
        cin>>n;
        vector<string> matchs(n);
        for(int i=0;i<n;i++){
            cin>>matchs[i];
        }
        auto ans=verify(matchs);
        if(ans.second){
            cout<<"Yay! Mighty Rafa persists!"<<endl;
        }else{
            cout<<ans.first<<endl;
        }
    }
    return 0;
}