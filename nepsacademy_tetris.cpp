#include <bits/stdc++.h>
#define pi pair<int,string>
#define f first
#define s second

using namespace std;

bool comp( pi a, pi b){
    if(a.f==b.f)
        return a.s<b.s;
    
    return a.f>b.f;
}

int main(){
    int n,a,acc,cont=1;
    string s;
    vector<int> v;
    vector<pi> classificacao;
    while(cin>>n,n){
        classificacao.clear();
        while(n--){
            v.clear();
            cin>>s;
            for(int i=0;i<12;i++){
                cin>>a;
                v.push_back(a);
            }
            acc=accumulate(v.begin(),v.end(),0);
            auto min=min_element(v.begin(),v.end());
            auto max=max_element(v.begin(), v.end());
            acc-= *min + *max;
            classificacao.push_back(pi(acc,s));
        }
        sort(classificacao.begin(),classificacao.end(), comp);
        
        int ant=1;
        cout<<"Teste "<< cont++<<endl<<1;
        for(int i=0; i<classificacao.size();i++){
            if(i>0){
                if(classificacao[i-1].f==classificacao[i].f){
                    cout<<ant;
                }else{
                    cout<<i+1;
                    ant=i+1;
                }
            }
            cout<<' '<<classificacao[i].f<<' '<<classificacao[i].s<<endl;
        }
        cout<<endl;
    }

    return 0;
}