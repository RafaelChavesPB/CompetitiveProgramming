#include <bits/stdc++.h>
#define DEBUG 
#define ll long long
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
        string s;
        cin>>s;
        ll ini = 0;
        ll total = 0;
        ll d;
        for(int i=0;i<s.size();i++){
            if(i>0){
                if(s[i]==s[i-1]){
                    d = i - ini;
                    total += ((d+1)*d)/2 - d;
                    ini = i;
                }
            }
            
            if(s[i]=='?'){
                int ant = i - 1;
                int q = 0;
                while(s[i]=='?' and i<s.size()){
                    q++;
                    i++;
                }
                if(i == s.size() or ant<0)
                    continue;
                
                if((s[ant]!=s[i] and q%2) or (s[ant]==s[i] and q%2==0)){
                    d = i - ini;
                    total += ((d+1)*d)/2 - d;
                    ini = ant+1;
                }   
            }
        }
        d = s.size() - ini;
        total += ((d+1)*d)/2 - d;
        cout<<total+s.size()<<endl;
    }


    return 0;
}