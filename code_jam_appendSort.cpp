#include <bits/stdc++.h>
using namespace std;

string inc(string a){
    int tam = a.size();
    for(int i=tam-1;i>=0;i--)
        if(a[i]=='9'){
            a[i]='0';
        }else{
            a[i]++;
            return a;
        }
    return '1'+a;
}

int testCase(){
    int n,ans=0;
    string cur, prv;
    cin>>n;
    cin>>prv;
    for(int i=0;i<n-1;i++){
        cin>>cur;
        if(cur.size()==prv.size()){
            if(cur<=prv){
                cur+='0';
                ans++;
            }
        }else if(cur.size()<prv.size()){
            string sub = prv.substr(0,cur.size());
            if(sub==cur){
                string a = inc(prv);
                if(a.substr(0,cur.size())==sub){
                    ans+=prv.size()-cur.size();
                    cur = a;
                }else{
                    while(cur.size()<=prv.size()){
                        ans++;
                        cur+='0';
                    }
                }
            }
            else if(sub<cur){
                while(cur.size()<prv.size()){
                    ans++;
                    cur+='0';
                }
            }else{
                while(cur.size()<=prv.size()){
                    ans++;
                    cur+='0';
                }
            }
        }
        prv=cur;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
        cout<<"Case #"<<T<<": "<<testCase()<<endl;
    }
    return 0;
}



