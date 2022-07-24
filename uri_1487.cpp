#include <iostream>
#include <vector>
#include <algorithm>

#define ii pair<int,int>

using namespace std;

vector<ii> rides(605,ii(0,0));

bool compare(ii a , ii b){

    return (a.second/(float)a.first)>(b.second/(float)b.first);
}

long guloso(int t, int n){
    long pontuacao=0;
    int tempo=0;
    for(int i=0;i<n;i++){
        while(tempo+rides[i].first<=t){
            tempo+=rides[i].first;
            pontuacao+=rides[i].second;
        }

        if(tempo==t){
            break;
        }
    }

    return pontuacao;
}
int main(){

    int ttemp, ptemp, n, t, test_case=0;

    while(cin>>n>>t&&n){
       for(int i=0;i<n;i++){
            cin>>ttemp>>ptemp;
            rides[i]=ii(ttemp,ptemp);
        }
        sort(rides.begin(), next(rides.begin(),n), compare);

        cout<<"Instancia "<<++test_case<<"\n";
        cout<<guloso(t,n)<<"\n\n";
    }


    return 0;
}