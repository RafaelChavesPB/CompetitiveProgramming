#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> s(4);
    for(int i=0;i<4;i++)
        cin>>s[i];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j>0 and i>0){
                if(s[i][j]!=s[i-1][j] and s[i][j]!=s[i][j-1] and s[i][j]!=s[i-1][j-1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j<3 and i<3){
                if(s[i][j]!=s[i+1][j] and s[i][j]!=s[i][j+1] and s[i][j]!=s[i+1][j+1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j>0 and i<3){
                if(s[i][j]!=s[i][j-1] and s[i][j]!=s[i+1][j] and s[i][j]!=s[i+1][j-1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j<3 and i>0){
                if(s[i][j]!=s[i][j+1] and s[i][j]!=s[i-1][j] and s[i][j]!=s[i-1][j+1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j>0 and i>0){
                if(s[i][j]==s[i-1][j] and s[i][j]==s[i][j-1] and s[i][j]==s[i-1][j-1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j<3 and i<3){
                if(s[i][j]==s[i+1][j] and s[i][j]==s[i][j+1] and s[i][j]==s[i+1][j+1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j>0 and i<3){
                if(s[i][j]==s[i][j-1] and s[i][j]==s[i+1][j] and s[i][j]==s[i+1][j-1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }

            if(j<3 and i>0){
                if(s[i][j]==s[i][j+1] and s[i][j]==s[i-1][j] and s[i][j]==s[i-1][j+1]){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}