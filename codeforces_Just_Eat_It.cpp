#include <bits/stdc++.h>

using namespace std;

vector<int> seq;

long long divq(int s, int e){


    if(s==e){
        return seq[s];
    }
    int m=(s+e)/2;
    long long metade=max(divq(s,m),divq(m+1,e));
    long long suml=0;
    long long sumr=0;
    long long left=seq[m];
    long long right=seq[m+1];

    for(int i=m; i>=s; i--){
        suml+=seq[i];
        left=max(left,suml);
    }

    for(int i=m+1;i<=e;i++){
        sumr+=seq[i];
        right=max(right,sumr);
    }
    
    return max(metade,left+right);
}

int main(){
    int cases, tam, temp;
    cin>>cases;
    while(cases--){
        seq.clear();
        cin>>tam;
        while(tam--){
            cin>>temp;
            seq.push_back(temp);
        }
        long long sum=0;
        for(auto x: seq){
            sum+=x;
        }
        long long v1=max(divq(0,seq.size()-2),divq(1,seq.size()-1));
        if(sum>v1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }


    return 0;
}