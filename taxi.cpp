#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,diff;
    int freq[5]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        freq[a]++;
    }
    // 3 e 1 
    diff = min(freq[3],freq[1]);
    freq[3] -= diff;
    freq[1] -= diff;
    freq[4] += diff;
    // 2 e 2
    diff = freq[2]/2;
    freq[2] %= 2; 
    freq[4] += diff;
    // 1 e 2 
    if(freq[2]){
        diff = min(2,freq[1]);
        freq[2] = 0;
        freq[2+diff]++;
        freq[1] -= diff; 
    }
    // 1 em 4,3,2,1,0
    diff = freq[1]/4;
    freq[1]%=4;
    freq[4] += diff;
    if(freq[1]>1){
        diff = freq[1];
        freq[1] = 0;
        freq[diff]++;
    }
    cout<<freq[1]+freq[2]+freq[3]+freq[4]<<endl;
    return 0;
} 