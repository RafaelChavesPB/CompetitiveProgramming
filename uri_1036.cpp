#include <bits/stdc++.h>

using namespace std;

int main (){
    
    float a,b,c,delta,root_delta;
    
    cin>>a>>b>>c;
    
    delta=b*b-4*a*c;
   
    cout<<fixed<<setprecision(5);

    if(delta>=0&&a!=0){
        root_delta=sqrt(delta);
        cout<<"R1 = "<< (-b+root_delta)/(2*a)<<endl;
        cout<<"R2 = "<< (-b-root_delta)/(2*a)<<endl;
    }
    else
    {
        cout<<"Impossivel calcular"<<endl;
    }
    
}