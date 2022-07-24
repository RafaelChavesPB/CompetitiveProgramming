#include <bits/stdc++.h>

using namespace std;

void print(vector<string> v){
    if(v.size()!=0){
        cout<<"\"";
        for(int i=0; i<v.size();i++){
            if(i)
                cout<<',';
            cout<<v[i];
        }
        cout<<"\""<<endl;    
    }else{
        cout<<"-"<<endl;
    }
}
int main(){
    string in;
    vector<string> ints;
    vector<string> not_ints;
    string temp;
    bool is_int=true;
    cin>>in;

    for(auto letter: in){
        if(letter==',' or letter==';'){
            if(temp.front()!='0' and is_int and temp.size()!=0){
                ints.push_back(temp);
            }else if(temp=="0"){
                ints.push_back(temp);
            }else{
                not_ints.push_back(temp);
            }   
            temp.clear();
            is_int=true;
        }else{
            temp+=letter;
            if(!isdigit(letter)){
                is_int=false;
            }
        }
    }
    if(temp.front()!='0' and is_int and temp.size()!=0){
        ints.push_back(temp);
    }else if(temp=="0"){
        ints.push_back(temp);
    }else{
        not_ints.push_back(temp);
    }

    print(ints);
    print(not_ints);
    return 0;
}