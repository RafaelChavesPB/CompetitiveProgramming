#include <bits/stdc++.h>

using namespace std;



int main(){
    int m,n,a,b,x,y,cont=1;
    while(cin>>m>>n, m or n){
        vector<vector<int>> tv(m,vector<int>(n)),ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>tv[i][j];
            }
        }
        x=y=0;
        while(cin>>a>>b,a or b){
            y-=b;
            x+=a;
        }
        y%=m;
        if(y<0)
            y+=m;
        x%=n;
        if(x<0)
            x+=n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[(i+y)%m][(j+x)%n]=tv[i][j];
            }
        }

        cout<<"Teste "<<cont++<<endl;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;


    }

    return 0;
}