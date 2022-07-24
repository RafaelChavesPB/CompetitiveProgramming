#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long n;
    cin>>n;
    for(int i=2; i<=n;i+=2){
        cout<<i<<"^2 = "<<(long)pow(i,2)<<"\n";
    }
    return 0;
}