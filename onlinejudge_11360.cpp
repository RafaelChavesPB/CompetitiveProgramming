#include <bits/stdc++.h>
using namespace std;

void row(int a, int b, vector<string> &c){
    swap(c[a],c[b]);
}
void col(int a,int b, vector<string> &c){
    for(int i=0;i<c.size();i++){
        swap(c[i][a],c[i][b]);
    }
}
void inc(vector<string> &c){
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c.size();j++){
            if(c[i][j]=='9')
                c[i][j]=='0';
            else 
                c[i][j]++;
        }
    }
}

void dec(vector<string> &c){
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c.size();j++){
            if(c[i][j]=='0')
                c[i][j]='9';
            else
                c[i][j]--;
        }
    }
}

void transpose(vector<string> &c){
    vector<string> d=c;
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c.size();j++){
            c[j][i]=d[i][j];
        }
    }
}
int main(){
    int t,n,m,a,b,cont=1;
    string op;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string> c(n);
        for(int i=0;i<n;i++){
                cin>>c[i];
        }
        cin>>m;
        while(m--){
            cin>>op;
            if(op=="transpose"){
                transpose(c);
            }else if(op=="row"){
                cin>>a>>b;
                row(a-1,b-1,c);
            }else if(op=="col"){
                cin>>a>>b;
                col(a-1,b-1,c);
            }else if(op=="inc"){
                inc(c);
            }else if(op=="dec"){
                dec(c);
            }
        }
        cout<<"Case #"<<cont++<<endl;
        for(auto i:c){
            cout<<i<<endl;
        }
        cout<<endl;
    }

}