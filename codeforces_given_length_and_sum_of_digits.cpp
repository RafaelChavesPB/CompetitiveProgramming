//cp template.cpp given_length_and_sum_of_digits.cpp && code given_length_and_sum_of_digits.cpp
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 100001
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,s;
    string l,g;
    cin>>m>>s;
    if(s == 0 and m > 1){
        cout<<0<<' '<<0<<endl;
    }else if(s == 0){
        cout<<-1<<' '<<-1<<endl;
    }else if(s/9 < m){
        int s_ = s;
        FOR(0,m){
            g += (char)(48 + min(9,s_));
            s_ -= min(9,s_);
        }
        if(s/9 == m-1 and s%9 != 0){
            l = (char)(48 + s%9) + string(m-1,'9');
        }else{
            s_ = s-1;
            FOR(0,m-1){
                l = (char)(48 + min(9,s_)) + l;
                s_ -= min(9,s_);
            }
            l = '1' + l;
        }
        cout<<l<<' '<<g<<endl;
    }else if(s/9 == m and s%9 == 0){
        int s_ = s;
        l = string(m,'9');
        cout<<l<<' '<<l<<endl;
    }else{
        cout<<-1<<' '<<-1<<endl;
    }
    return 0;
}