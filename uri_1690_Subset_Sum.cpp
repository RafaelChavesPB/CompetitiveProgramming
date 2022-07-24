#include <bits/stdc++.h>

using namespace std;

int main(){
    long long temp,total;
    int n, cases, flag;
    vector<long> v;
    scanf("%d",&cases);
    while(cases--){
        v.clear();
        total=0;
        flag=0;
        scanf("%d",&n);
        while(n--){
            scanf("%lld",&temp);
            v.push_back(temp);
            if(temp==1){
                flag=1;
            }
        }
        if(!flag){
            printf("1\n");
            continue;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(total<v[i]-1){
                break;
            }
            total+=v[i];
        }
        
        printf("%lld\n",total+1);
        
    }
}