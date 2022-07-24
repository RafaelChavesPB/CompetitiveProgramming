#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a,b,c;
    int n,temp;
    cin>>n;
    while(n--){
        cin>>temp;
        if(temp<0)
            b.push_back(temp);
        else if(temp>0)
            a.push_back(temp);
        else 
            c.push_back(temp); 
    }
    if(b.size()%2==0){
        c.push_back(b.back());
        b.pop_back();
    }
    if(a.size()==0){
        a.push_back(b.back());
        b.pop_back();
        a.push_back(b.back());
        b.pop_back();
    }
    cout<<b.size();
    for(auto i : b)
        cout<<' '<<i;
    cout<<endl<<a.size();
    for(auto i : a)
        cout<<' '<<i;
    cout<<endl<<c.size();
    for(auto i : c)
        cout<<' '<<i;
    cout<<endl;
    return 0;
}