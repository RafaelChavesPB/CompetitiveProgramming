#include <bits/stdc++.h>

using namespace std;

int main(){


    set<long long> s;
    long long a,n;

    cin>>n;
    while(n--){
        cin>>a;
        s.insert(a);
    }

    cout<<s.size()<<endl;
}