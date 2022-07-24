#include <bits/stdc++.h>

using namespace std;



int main(){
    int n, d, a, count=0;
    cin>>n>>d;
    vector<int> v(2*n+1),ps(2*n+1);
    ps[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[n+i]=v[i];    
    }

    for(int i=1;i<=2*n;i++){
        ps[i]=ps[i-1]+v[i];        
    }

    if(ps[n]<d){
        cout<<0<<endl;
        return 0;
   }

    for(int i=1; i<=n;i++){
        int  inicio=i+1,fim=i+n-1;
        while(inicio<fim){
            int meio=(fim+inicio)/2;
            int dif=ps[meio]-ps[i-1];
            if(dif<d){
                inicio=meio+1;
            }else if(dif>d){
                fim=meio-1;
            }else{
                fim=meio;
                break;
            }
        }
        if(ps[fim]-ps[i-1]==d){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}

//5 10 1 2 3 4 3