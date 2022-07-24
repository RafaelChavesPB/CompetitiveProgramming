#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum2=0,sum4=0, sum6=0, sum8=0;
    int n,m,l;
    string op;
    cin>>n;
    vector<int> count(100001);
    for(int i=1;i<=n;i++){
        cin>>l;
        count[l]++;
    }
    for(auto v:count)
        if(v>=8)
            sum8++;
        else if(v>=6)
            sum6++;
        else if(v>=4)
            sum4++;
        else if(v>=2)
            sum2++;
    cin>>m;
    while(m--){
        cin>>op>>l;
        if(op == "+"){
            count[l]++;
            if(count[l]==8){
                sum6--;
                sum8++;
            }else if(count[l]==6){
                sum4--;
                sum6++;
            }else if(count[l]==4){
                sum4++;
                sum2--;
            }else if(count[l]==2){
                sum2++;
            }
        }else{
            count[l]--;
            if(count[l]==7){
                sum6++;
                sum8--;
            }else if(count[l]==5){
                sum4++;
                sum6--;
            }else if(count[l]==3){
                sum4--;
                sum2++;
            }else if(count[l]==1){
                sum2--;
            }
        }
        if(sum8 or sum6 >=2 or (sum6 == 1 and (sum4 or sum2)) or sum4 >= 2 or (sum4==1 and sum2>=2)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}