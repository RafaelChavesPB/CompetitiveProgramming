#include <bits/stdc++.h>
#define debug_(x,y,z) cout<<"pos:"<<(x)<<" car:"<<(y)<<" mod:"<<(z)<<endl
#define debug(x) cout<<"N: "<<(x)<<endl
using namespace std;
int main()
{
    int n,cont=0;
    while (cin >> n, n)
    {
        int a, b;
        int flag = 1;
        vector<int> pole(n, 0);
        // debug(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            int pos = i + b;
            if(pos>=0 and pos<n){
                pole[pos]=a;
            }else{
                // debug_(i,a,b);
                flag=0;
            }
        }
        for(auto x:pole){
            if(x==0){
                flag=0;
                break;
            }
        }
        if(flag){
            string ans;
            for(auto x:pole){
                ans+=to_string(x)+' ';
            }
            ans.pop_back();
            cout<<ans<<endl; 
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}