#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        char dir='x';
        int sent=1;
        string in;
        for(int i=0;i<n-1;i++){
            cin>>in;
            if(in!="No")
                if(dir=='x'){
                    dir=in.back();
                    if(in.front()=='-')
                        sent*=-1;
                }else if(in.back()==dir){
                        dir='x';
                        if(in.front()=='+')
                        sent*=-1;
                }
        }
        if(sent>0){
            cout<<'+';
        }else{
            cout<<'-';
        }
        cout<<dir<<endl;
    }
    return 0;
}