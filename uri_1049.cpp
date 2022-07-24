#include <iostream>

using namespace std;

int main(){
    string c1,c2,c3;

    cin>>c1>>c2>>c3;

    if(c1=="vertebrado"){
        if(c2=="ave"){
            if(c3=="carnivoro"){
                cout<<"aguia\n";
            }else{
                cout<<"pomba\n";
            }
        }else {
            if(c3=="onivoro"){
                cout<<"homem\n";
            }else {
                cout<<"vaca\n";
            }
        }
    } else{
        if(c2=="inseto"){
            if(c3=="hematofago"){
                cout<<"pulga\n";
            }else {
                cout<<"lagarta\n";
            }
        } else {
            if(c3=="hematofago"){
                cout<<"sanguessuga\n";
            } else if(c3=="onivoro") {
                cout<<"minhoca\n";
            }
        }
    }
}