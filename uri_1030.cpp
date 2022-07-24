#include <iostream>

using namespace std;

int quemsobrou(int n, int k){
    if(n==1)
        return 1;
    return ((quemsobrou(n-1,k)+k-1)%n)+1;
}

int main(){

    std::ios::sync_with_stdio(false);
    int n,k,casos,count=0;

    cin>>casos;
    while(casos!=count){
        
        count++;
        cin>>n>>k;
        cout<<"Case "<<count<<": "<<quemsobrou(n,k)<<"\n";
        
    }
    
}