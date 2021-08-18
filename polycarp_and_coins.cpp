#include <bits/stdc++.h>
#define DEBUG 
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
#else
    #define bug(X) {;}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n;
        a = n/3;
        b= n/3;
        if(n%3 == 1){
            a++;
        }else if(n%3 == 2){
            b++;
        }
        cout<<a <<' '<<b<<endl;
    }
    return 0;
}