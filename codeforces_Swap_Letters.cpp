#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    vector<pi> coord;
    string str, str2;
    int n, count=0, ab=-1,ba=-1;
    cin>>n;
    cin>>str>>str2;

    for(int i=0; i<n; i++){
        if(str[i]=='a' and str2[i]=='b'){
            if(ab!=-1){
                count++;
                coord.push_back(pi(ab,i));
                ab=-1;
            }else{
                ab=i;
            }
        }else if(str[i]=='b' and str2[i]=='a'){
            if(ba!=-1){
                count++;
                coord.push_back(pi(ba,i));
                ba=-1;
            }else{
                ba=i;
            }
        }
    }
    if(ab==-1 and ba==-1){
        cout<<count<<'\n';
        for(auto x: coord){
            cout<<x.f+1<<" "<<x.s+1<<'\n';
        }
    }else if(ab!=-1 and ba!=-1){
        cout<<count+2<<'\n';
        for(auto x: coord){
            cout<<x.f+1<<" "<<x.s+1<<'\n';
        }
        cout<< ab+1 <<" "<<ab+1<<'\n';
        cout<< ba+1 <<" "<<ab+1<<'\n';
    }else{
        cout<<"-1\n";
    }
    return 0;
}