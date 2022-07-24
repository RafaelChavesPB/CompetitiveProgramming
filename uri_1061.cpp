#include <iostream>

using namespace std;

struct qtempo{

    int d;
    int h;
    int m;
    int s;
};

int main(){

    struct qtempo x,y,t;
    string str;
    char c;

    cin>>str>>x.d>>x.h>>c>>x.m>>c>>x.s>>str>>y.d>>c>>y.h>>c>>y.m>>c>>y.s;
    t.s=t.m=t.h=t.d=0;
    
    t.s+=y.s-x.s;
    if(t.s<0){
        t.s+=60;
        t.m--;
    }

    t.m+=y.m-x.m;
    if(t.m<0){
        t.m+=60;
        t.h--;
    }

    t.h+=y.h-x.h;
    if(t.h<0){
        t.h+=24;
        t.d--;
    }

    t.d+=y.d-x.d;

    cout<<t.d<<" dia(s)\n";
    cout<<t.h<<" hora(s)\n";
    cout<<t.m<<" minuto(s)\n";
    cout<<t.s<<" segundo(s)\n";
    return 0;
}