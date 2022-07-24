#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> s;
    int n;
    int tam;
    int temp;
    cin>>n;
    while(n--){
        cin>>tam;
        while(tam--){
            cin>>temp;
            s.push_back(temp);
        }
        sort(s.begin(),s.end());
        bool flag=true;
        for(int i=1;i<s.size();i++){
            if(abs(s[i]-s[i-1])==1){
                cout<<2<<endl;
                flag=false;
                break;
            }    
        }
        if(flag) cout<<1<<endl;
        s.clear();
    }
}