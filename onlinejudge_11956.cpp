#include <bits/stdc++.h>
using namespace std;
char encode(int a){
    if(a<10){
        return '0'+a;
    }else{
        return 'A'+(a-10);
    }
}
int main(){
    int t,cont=1;
    cin>>t;
    while(t--){
        vector<int> bytes(100,0);
        string s;
        int it=0;
        cin>>s;
        for(auto c:s){
            if(c=='+'){
                if(bytes[it]==255)
                    bytes[it]=0;
                else
                    bytes[it]++;
            }
            else if(c=='-'){
                if(bytes[it]==0)
                    bytes[it]=255;
                else
                    bytes[it]--;
            }else if(c=='>'){
                if(it==99)
                    it=0;
                else
                    it++;
            }else if(c=='<'){
                if(it==0)
                    it=99;
                else
                    it--;
            }
        }
        cout<<"Case "<<cont++<<":";
        for(auto x : bytes){
            cout<<' '<<encode(x/16)<<encode(x%16);
        }
        cout<<endl;
    }
    return 0;
}
