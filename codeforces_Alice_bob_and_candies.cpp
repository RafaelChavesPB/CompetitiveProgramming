#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> fd;
    int t,n,a,b,sum_a,sum,round;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>a;
            fd.push_back(a);
        }
        round=1;
        sum_a=sum=a=b=0;
    
        while(!fd.empty()){
            if(round%2){
                sum+=fd.front();
                fd.pop_front();
            }else{
                sum+=fd.back();
                fd.pop_back();
            }
            if(sum>sum_a){
                if(round%2){
                    a+=sum;
                }else{
                    b+=sum;
                }
                sum_a=sum;
                sum=0;
                round++;
            }
        }
        if(sum)
            if(round%2){
                a+=sum;
            }else{
                b+=sum;
            }
        else
        {
            round--;
        }
        
        cout<<round<<' '<<a<<' '<<b<<endl;
    }

    return 0;
}