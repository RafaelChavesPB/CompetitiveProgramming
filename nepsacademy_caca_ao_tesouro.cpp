#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;

bool isSubsetSum(int sum){

    vector<vector<bool>> mem(n+1,vector<bool>(sum+1,0));
    for(int i=0;i<=n;i++)
        mem[i][0]=true;
    for(int j=1;j<=sum;j++)
        mem[0][j]=false;

    for(int i=1;i<=n;i++)
        for(int j=1; j<=sum;j++)
            if(j<v[i-1])
                mem[i][j]=mem[i-1][j];
            else
                mem[i][j]=(mem[i-1][j]||mem[i-1][j-v[i-1]]);
                
    /* for (int i = 0; i <= n; i++)
     {
           for (int j = 0; j <= sum; j++)
                  printf ("%4d", subset[i][j]);
           printf("\n");
     }*/

     return mem[n][sum];
}






int main(){
    int a,b,c, acc, cont=1;

    while(cin>>a>>b>>n, a or b or n){
        v.clear();
        for(int i=0;i<n;i++){
            cin>>c;
            v.push_back(c);
        }

        acc=accumulate(v.begin(),v.end(),0);

        auto total=a+b+acc;

        cout<<"Teste "<<cont++<<endl;
        if(total%2){
            cout<<"N"<<endl;
        }else{
            auto sum=(total/2)-min(a,b);
            if(isSubsetSum(sum)){
                cout<<"S"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}