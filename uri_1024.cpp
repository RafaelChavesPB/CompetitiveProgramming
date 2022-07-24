#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    
    string str;
    int tam,num;

    cin>>num;
    cin.ignore();

    for(int j=0;j<num;j++){

        getline(cin,str);
        tam=str.size();
        std::reverse(str.begin(),str.end());

        for(auto& letra: str)
            if(isalpha(letra))letra+=3;
        
        for(int i=tam/2;i<tam;i++)
            str[i]-=1;

        cout<<str<<endl;
    }
}