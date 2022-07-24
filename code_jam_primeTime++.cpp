#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> v;

int main()
{
    long long t;
    cin >> t;
    for (long long T = 1; T <= t; T++)
    {
        long long m, n, p;
        long long sum_total=0,ans=0;
        v.clear();
        cin >> m;
        for(long long i=0;i<m;i++){
            cin>>p>>n;
            v.push_back({p,n});
            sum_total+=p*n;
        }
        for(long long i=2;i<min((long long)5000,sum_total-1);i++){
            long long num=sum_total-i;
            long long sum=0;
            bool flag=true;
            for(auto it:v){
                long long cont=0;
                while(num%it.first==0){
                    num/=it.first;
                    sum+=it.first;
                    cont++;
                }
                if(cont>it.second){
                    flag=false;
                    break;
                } 
            }
            if(num==1 and flag and sum==i){
                ans = sum_total-i;
                break;
            }
        }
        cout << "Case #" << T << ": " << ans << endl;
        //P1*P2*P3 = SUM_TOTAL - P1 - P2 - P3
        //P1*P2*P3 = SUM_TOTAL - SUM_G2
        //Fatorando Sum_g2 em primos nos obtemos uma unica sequência de primos,
        //se ela couber dentro da entrada então é uma resposta válida.
        //Detalhe que a resposta é iobtida com a menor Sum_G2 válida.
        //Calcular soma total e receber a entrada
        //Iterar SUm_g2 de 1 a 3000
        //Fatorar Sum_g2 e verificar se é valida
        //Para ser válida a quantidade de cada primo tem  que ser menor que a da entrada
        //A fatoração deve ser feita só com os primos da entrada
        //Se e o resto da fatoração for então pode ser válida
    }
    return 0;
}