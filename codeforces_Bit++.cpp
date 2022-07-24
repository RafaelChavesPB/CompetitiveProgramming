#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,x=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.back()=='-' or s.front()=='-'){
            x--;
        }else{
            x++;
        }
    }
    cout<<x<<endl;
    
    return 0;
}
