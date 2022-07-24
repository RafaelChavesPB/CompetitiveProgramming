#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string tp1, tp2;
    map<double,string> mapa;
    int n;  

    cin>>n;
    while(n--){
        cin>>tp1>>tp2;
        if(isdigit(tp1[0])){
            mapa[atoi(tp1.c_str())/2.0]=tp2;
        }else{
            mapa[atoi(tp2.c_str())]=tp1;
        }
    }

    for(auto x : mapa){
        cout<<x.second<<endl;
    }
    return 0;
}
