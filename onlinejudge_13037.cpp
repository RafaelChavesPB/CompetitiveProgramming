#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a;
    cin>>t;
    for(int caso=1;caso<=t;caso++){
        int v[3];
        int cont[3]={0}, cont2[3]={0};
        set<int> s[3];
        for(int i=0;i<3;i++) 
            cin>>v[i];
        for(int i=0;i<3;i++){
            for(int j=0;j<v[i];j++){
                cin>>a;
                s[i].insert(a);
            }
        }
        for(int i=0;i<3;i++){
            for(auto x: s[i]){
                if(s[(i+1)%3].find(x)==s[(i+1)%3].end() and s[(i+2)%3].find(x)==s[(i+2)%3].end())
                    cont[i]++;
                else if(s[(i+1)%3].find(x)==s[(i+1)%3].end()){
                    cont2[(i+1)%3]++;
                }else if(s[(i+2)%3].find(x)==s[(i+2)%3].end()){
                    cont2[(i+2)%3]++;
                }
            }
        }
        cout<<"Case #"<<caso<<":"<<endl;
        for(int i=0;i<3;i++){
            cout<<cont[i]<<' '<<cont2[i]/2<<endl;
        }
    }
    return 0;
}