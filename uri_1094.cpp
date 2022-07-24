#include <bits/stdc++.h>

using namespace std;

int main(){
    char type;
    int total=0;
    int c=0,r=0,s=0;
    int n,q;
    ios::sync_with_stdio(false);

    cout<<fixed<<setprecision(2);

    cin>>n;

    while(n--){
        cin>>q>>type;
        
        total+=q;

        switch(type){
            case 'C':
                c+=q;
                break;
            case 'R':
                r+=q;
                break;
            case 'S':
                s+=q;
                break;
        }
    }

    cout<<"Total: "<<total<<" cobaias\n";
    cout<<"Total de coelhos: "<<c<<"\n";
    cout<<"Total de ratos: "<<r<<"\n";
    cout<<"Total de sapos: "<<s<<"\n";
    cout<<"Percentual de coelhos: "<<(c*100.0)/total<<" %\n";
    cout<<"Percentual de ratos: "<<(r*100.0)/total<<" %\n";
    cout<<"Percentual de sapos: "<<(s*100.0)/total<<" %\n";
}