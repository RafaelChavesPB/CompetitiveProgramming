#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,cont=1;
    while(cin>>n>>m, n and m){
        vector<int> t(n,0);
        int maior=-INT_MAX, menor=INT_MAX, somatorio=0;
        for(int i=0; i< n ;i++){
            cin>>t[i];
            if(i<m)
                somatorio+=t[i];
        }
        maior=max(somatorio/m,maior);
        menor=min(somatorio/m,menor);
        for(int i=0, j=m;j<n;i++,j++){
            somatorio+=-t[i]+t[j];
            maior=max(somatorio/m,maior);
            menor=min(somatorio/m,menor);
        }
        cout<<"Teste "<<cont++<<endl;
        cout<<menor<<' '<<maior<<endl<<endl;
    }

    return 0;
}