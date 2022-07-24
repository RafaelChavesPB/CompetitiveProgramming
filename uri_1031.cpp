#include <iostream>
#include <vector>

using namespace std;

int quemsobrou(int n, int k){
    if(n==1)
        return 1;
    return ((quemsobrou(n-1,k)+k-1)%n)+1;
}

int main(){

    int n, k, qvs;

    while(cin>>n&&n!=0)
        for(int k=1;k<30000;k++){
            qvs=(quemsobrou(n,k)-k)%n+1;
            if((qvs<=0?(qvs+n):qvs)==13){
                cout<<k<<endl;
                break;
            }
        }    

}