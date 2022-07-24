#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

bool proc(vvi vv, int num){
    for(auto x: vv){
        if(num!=x[0] and num!=x[1])
            return false;
    }
    return true;
}
int main(){
    int n,cont=1,a,b;
    vector<string> but={"A","B","C","D","E"};

    while(cin>>n,n){
        map<string,vvi> codigos;
        vector<vector<string>> dig;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                vi temp;
                cin>>a>>b;
                codigos[but[j]].push_back({a,b});
            }
            vector<string> atual;
            for(int j=0;j<6;j++){
                string temp;
                cin>>temp;
                atual.push_back(temp);
            }
            dig.push_back(atual);
        }
        
        cout<<"Teste "<<cont++<<endl;
        for(int i=0;i<6;i++){
            vvi vv;
            for(int j=0;j<n; j++){
                auto letra=dig[j][i];
                vv.push_back(codigos[letra][j]);
            }
            if(proc(vv,vv[0][0])){
                cout<<vv[0][0]<<' ';
            }else{
                cout<<vv[0][1]<<' ';
            }
        }
        cout<<endl<<endl;


    }

}