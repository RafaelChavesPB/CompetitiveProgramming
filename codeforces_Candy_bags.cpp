#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    deque<int> dq;
    cin>>n;
    for(int i=1;i<=n*n;i++){
        dq.push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j+=2){
            if(j)
                cout<<' ';
            cout<<dq.front()<<' '<<dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}