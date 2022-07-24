#include <bits/stdc++.h>

using namespace std;

int main(){

    int pum=1, n;

    cin>>n;

    for(int i=0;i<n;i++){
        cout<<pum++<<" "<<pum++<<" "<<pum<<" PUM\n";
        pum+=2;
    }


    return 0;
}