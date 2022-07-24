#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

        int m, n;
        
        map<string,string> dic;
        string a, b, trad;

        cin>>m>>n;
        cin.ignore();
        while(m--){
            getline(cin,a);
            getline(cin,b);
            dic[a]=b;
        }
        while(n--){
            getline(cin,a);
            istringstream iss(a);
            while(iss>>a){
                if(dic.find(a)==dic.end()){
                    trad+=a+' ';
                }else{
                    trad+=dic[a]+' ';
                }
            }
            trad.pop_back();
            cout<<trad<<endl;
            trad.clear();
        }
        cout<<endl;


    }


    return 0;
}