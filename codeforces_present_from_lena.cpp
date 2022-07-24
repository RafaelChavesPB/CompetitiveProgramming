#include  <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> m(2*n+1,vector<int>(2*n+1,-1));
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            if(i<=n){
                if(j<=n){
                    if(i+j>=n)
                        m[i][j]=i+j-n;
                }else{
                    if(n+i>=j)
                        m[i][j]=n+i-j;
                }   
            }else{
                if(j<=n){
                    if(n+j>=i)
                        m[i][j]= -i+j+n;
                }else{
                    if(3*n>=j+i)
                        m[i][j]=3*n-i-j;
                }  
            }
        }
    }
    for(auto i:m){
        string s;
        for(auto j:i){
            if(j>=0){
                s+='0'+j;
                s+=' ';
            }
            else{
                s+="  ";
            }
        }
        while(s.back()==' '){
            s.pop_back();
        }
        cout<<s<<endl;
    }



    return 0;
}