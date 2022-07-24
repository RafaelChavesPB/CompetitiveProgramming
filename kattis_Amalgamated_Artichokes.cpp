#include <bits/stdc++.h>

using namespace std;

double price(double k,double p,double a, double b, double c, double d){
    return p*(sin(a*k+b)+cos(c*k +d)+2);
}

int main(){
    double a,b,c,d,p,n;
    double mini=INT_MAX, maxi=INT_MIN, melhor=0.00,temp;
    double m[1000010]={0};
    cin>>p>>a>>b>>c>>d>>n;

    for(int k=1;k<=n;k++){
        m[k]=price(k,p,a,b,c,d);
    }
    for(int i=n;i>0;i--){
        if(m[i]<mini){
            mini=m[i];
            maxi=INT_MIN;
        }else if(m[i]>maxi){
            maxi=m[i];
            temp=maxi-mini;
            if(temp>melhor){
                melhor=temp;
            }
        }
    }
    printf("%lf\n",melhor);
    return 0;
}