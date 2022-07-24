#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, ex, ey, n;
    char v,h;
    string s;
    cin >> n >> x >> y >> ex >> ey >> s;
    int difx=abs(x-ex), dify=abs(y-ey);
    if(ex>x){
        h='E';
    }else if(ex<x){
        h='W';
    }else{
        h='a';
    }
    if(ey>y){
        v='N';
    }else if(ey<y){
        v='S';
    }else{
        v='a';
    }

    int contx=0, conty=0;
    for(auto c: s){
        if(h==c){
            contx++;
        }else if(v==c){
            conty++;
        }
    }
    // if(conty<dify or contx<difx){
    //     cout<<-1<<endl;
    //     return 0;
    // }
    for(int i=0;i<s.size();i++){
        if(h==s[i] and difx){
            difx--;
        }
        if(v==s[i] and dify){
            dify--;
        }
        if(!difx and !dify){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}