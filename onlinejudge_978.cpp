#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sb,sg,a,bf;
        cin>>n>>sg>>sb;
        priority_queue<int> b,g;
        while(sg--){
            cin>>a;
            g.push(a);
        }
        while(sb--){
            cin>>a;
            b.push(a);
        }
        while(bf=min((int)b.size(),min((int)g.size(),n)), bf){
            vector<int> vb(bf),vg(bf);
            for(int i=0;i<bf;i++){
                vb[i]=b.top();
                b.pop();
                vg[i]=g.top();
                g.pop();
            }
            for(int i=0;i<bf;i++){
                if(vg[i]>vb[i]){
                    g.push(vg[i]-vb[i]);
                }else if(vb[i]>vg[i]){
                    b.push(vb[i]-vg[i]);
                }
            }
        }
        if(b.size()>g.size()){
            cout<<"blue wins"<<endl;
            while(b.size()){
                cout<<b.top()<<endl;
                b.pop();
             }
        }else if(g.size()>b.size()){
            cout<<"green wins"<<endl;
            while(g.size()){
                cout<<g.top()<<endl;
                g.pop();
            }
        }else{
            cout<<"green and blue died"<<endl;
        }
        if(t)
            cout<<endl;
    }
    return 0;
}