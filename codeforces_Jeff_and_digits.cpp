#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, n0=0, n5=0, temp;
    string ans;
    cin>>n;
    while (n--) {
        cin>>temp;
        if (temp==5)
            n5++;
        else if (temp==0)
            n0++;
    }
    if (n0) {
        do {
            if ((n5*5)%9==0) {
                ans=string(n5, '5');
                break;
            }
        } while (--n5);
        if (!ans.empty()) {
            ans+=string(n0, '0');
        }        
        else {
            ans="0";
        }
        cout<<ans<<endl;
    }    
    else {  
        cout<<-1<<endl;
    }
}