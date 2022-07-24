#include <bits/stdc++.h>

using namespace std;

int main(){

    int x,y;
    cout<<fixed<<setprecision(2);

    cin>>x>>y;

    cout<<"Total: R$ ";
    
    switch (x)
    {
        case 1:
            cout<<y*4.00<<"\n";            
            break;
        case 2:
            cout<<y*4.50<<"\n";            
            break;
        case 3:
            cout<<y*5.00<<"\n";            
            break;
        case 4:
            cout<<y*2.00<<"\n";            
            break;
        case 5:
            cout<<y*1.50<<"\n";            
            break;
        
        default:
            break;
    }
    return 0;
}