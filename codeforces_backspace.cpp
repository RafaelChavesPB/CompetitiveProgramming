//Problema disponivel em: https://codeforces.com/problemset/problem/1553/D
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
        string s,t,u;
        cin>>s>>t;
        if(s.size()<t.size()){
            cout<<"NO"<<endl;
        }else{
            int i = s.size()-1;
            int j = t.size()-1;
            while(i >= 0){
                if(j >= 0){
                    if(s[i] == t[j]){
                        u+=s[i--];
                        j--;
                    }else{
                        i-=2;
                    }
                }else{
                    break;
                }
            }
            reverse(u.begin(),u.end());
            if(u==t){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}