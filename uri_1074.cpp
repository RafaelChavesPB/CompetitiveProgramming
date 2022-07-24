#include <iostream>

using namespace std;

int main(){

    int n,temp;
    cin>>n;

    while(n--){
        cin>>temp;
        if(temp==0){
            cout<<"NULL\n";
        } else{
            if(temp%2){
                cout<<"ODD ";
            } else{
                cout<<"EVEN ";
            }
            if(temp<0){
                cout<<"NEGATIVE\n";
            }else {
                cout<<"POSITIVE\n";
            }
        }
    }
    return 0;
}