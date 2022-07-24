#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> original ={"Happy","birthday","to","you","Happy","birthday","to","you",
                            "Happy","birthday","to","Rujia","Happy","birthday","to","you"};
    vector<string> family,music;

    int n;
    cin>>n;
    while(music.size()<n){
        for(auto s:original)
            music.push_back(s);
    }
    for(int i=0;i<n;i++){
        family.push_back("");
        cin>>family.back();
    }
    for(int i=0,j=0;i<music.size();i++,j++){
        j%=n;
        cout<<family[j]<<": "<<music[i]<<endl;
    }
    return 0;
}