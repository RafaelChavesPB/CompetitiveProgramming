#include <bits/stdc++.h>
using namespace std;
vector<int> red;
vector<int> blue;
int cred(int a, int b, int ultimo);
int cblue(int a, int b, int ultimo);
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        red.clear();
        blue.clear();
        cin>>n;
        while(n--){
            cin>>a;
            if(a<0)
                red.push_back(-a);
            else
                blue.push_back(a);
        }
        sort(red.begin(),red.end(),greater<int>());
        sort(blue.begin(),blue.end(),greater<int>());
        cout<<max(cred(0,0,INT_MAX),cblue(0,0,INT_MAX))<<endl;
    }
    return 0;
}

int cred(int a, int b, int ultimo){
    if(a==red.size())
        return 0;
    if(red[a]<ultimo)
        return cblue(a+1,b,red[a]) + 1 ;
    return cred(a+1,b,ultimo);
}
int cblue(int a, int b, int ultimo){
    if(b==blue.size())
        return 0;
    if(blue[b]<ultimo)
        return cred(a, b+1, blue[b]) + 1;
    return cblue(a,b+1,ultimo);
}
