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
        int q = 0;
        int extra = 0;
        string s;
        cin>>s;
        int arr[27]={0};
        for(auto it:s){
            arr[it-'a']++;
        }
        for(int i=0;i<27;i++){
            if(arr[i]>=2){
                q++;
            }else if(arr[i]==1){
                extra++;
            }
        }
        cout<<q+extra/2<<endl;
    }
    return 0;
}