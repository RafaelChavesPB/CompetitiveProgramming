#include <bits/stdc++.h>

using namespace std;

class coord{
    public:
        long long x1,x0,y1,y0;
        coord();
        coord(long long xa, long long xb, long long ya, long long yb);
        long long area(void);
        coord operator & (coord b);
};

coord::coord(){};
coord::coord(long long xa, long long xb, long long ya, long long yb){
    x1=xb;
    x0=xa;
    y1=yb;
    y0=ya;
}

long long coord::area(void){
            if(x0==-1 and x1==-1 and y0==-1 and y1==-1)
                return 0;
            return abs((y1-y0)*(x1-x0));
        }

coord coord::operator & (coord b){
            coord temp;
            if(b.y0>=y1 or b.y1<=y0 or b.x0>=x1 or b.x1<=x0){
                return coord(-1,-1,-1,-1);
            }
            return coord(max(x0,b.x0),min(x1,b.x1),max(y0,b.y0),min(y1,b.y1));
        }

int main(){
    coord b1,b2,w,i1,i2,i3;
    cin>>w.x0>>w.y0>>w.x1>>w.y1;
    cin>>b1.x0>>b1.y0>>b1.x1>>b1.y1;
    cin>>b2.x0>>b2.y0>>b2.x1>>b2.y1;
    i1=b1&w;
    i2=b2&w;
    i3=i1&i2;
    if(w.area()==(i2.area()+i1.area()-i3.area())){
        // cout<<w.area()<<endl;
        // cout<<b1.area()<<endl;
        // cout<<b2.area()<<endl;
        cout<<"NO\n";
    }else{
        // cout<<w.area()<<endl;
        // cout<<b1.area()<<endl;
        // cout<<b2.area()<<endl;
        cout<<"YES\n";
    }
    
}