#include <bits/stdc++.h>
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(long long i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        string s;
        long long size;
        cin>>size;
        cin>>s;
        vector<long long> p;
        for(long long i=0;i<s.size();i++){
            if(s[i]=='*'){
                p.push_back(i);
            }
        }
        long long n = p.size();
        vector<long long> to_left(n,0), to_right(n,0);
        for(long long i=1;i<n;i++){
                to_right[i] = to_right[i-1]+i*(p[i]-p[i-1]-1); 
        }

        for(long long i = n-2; i >= 0; i--){
            to_left[i] = to_left[i+1] + (n-i-1)*(p[i+1]-p[i]-1); 
            long long q = n-1-i;
        }
        long long ans = 9223372036854775807;
        for(long long i=0;i<p.size();i++){
            ans = min(ans,to_left[i]+to_right[i]);
        }
        bugV(to_left,to_left.size());
        bugV(to_right,to_right.size());
        if(ans == 9223372036854775807){
            cout<<0<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}