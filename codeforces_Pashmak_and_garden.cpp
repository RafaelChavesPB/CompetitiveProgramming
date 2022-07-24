#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int dify=abs(y1-y2);
    int difx=abs(x1-x2);
    if(x1==x2){
        cout<<x1+dify<<' '<<y1<<' '<<x1+dify<<' '<<y2<<endl;
    }else if(y1==y2){
        cout<<x1<<' '<<y1+difx<<' '<<x2<<' '<<y1+difx<<endl;
    }else if(difx==dify){
        cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}