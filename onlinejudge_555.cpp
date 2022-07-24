#include <bits/stdc++.h>
using namespace std;
int main(){
    char start;
    string naipe="CDSH";
    string dir="SWNE";
    string face="23456789TJQKA";
    map<char,int> dict_naipe,dict_face,dict_dir;
    for(int i=0;i<naipe.size();i++){
        dict_naipe[naipe[i]]=i;
        dict_dir[dir[i]]=i;
    }
    for(int i=0;i<face.size();i++){
        dict_face[face[i]]=i;
    }
    while(cin>>start, start!='#'){
        string in,temp;
        vector<pair<int,int>> hands[4];
        cin>>in>>temp;
        in+=temp;
        for(int i=0, hand=(dict_dir[start]+1)%4;i<in.size();i+=2,hand=(hand+1)%4)
            hands[hand].push_back({dict_naipe[in[i]],dict_face[in[i+1]]});
        
        for(int i=0;i<4;i++){
            sort(hands[i].begin(),hands[i].end());
            cout<<dir[i]<<':';
            for(auto p : hands[i]){
                cout<<' '<<naipe[p.first]<<face[p.second];
            }
            cout<<endl;
        }
    }   
    return 0;
}