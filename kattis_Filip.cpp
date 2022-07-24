#include <bits/stdc++.h>

using namespace std;

int inverte(int num){
    int a,b,c;
    c= num/100;
    num%=100;
    b=(num/10);
    num%=10;
    a=num;
    return 100*a+10*b+c;
}
int main(){
    int n1, n2, nr1, nr2;
    cin>>n1>>n2;

    nr1=inverte(n1);
    nr2=inverte(n2);
    cout<<(nr1>nr2?nr1:nr2)<<"\n";
    return 0;
}