#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,a,b,cont=0;
    char c;
    while(cin>>m,m){
        cin>>a;
        for(int i=1;i<m;i++){
            cin>>c>>b;
            if(c=='+')
                a+=b;
            else 
                a-=b;
        }
        cout<<"Teste "<<++cont<<endl<<a<<endl<<endl;
    }


    return 0;
}