#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    
    double a,b,c;
    cout<<fixed<<setprecision(1);
    cin>>a>>b>>c;

    if((a>abs(b-c)&&a<b+c)||(b>abs(a-c)&&b<a+c)||(c>abs(a-b)&&c<a+b)){
        cout<<"Perimetro = "<<a+b+c<<"\n";
    }
    else{
        cout<<"Area = "<<((a+b)*c)/2<<"\n";
    }

}