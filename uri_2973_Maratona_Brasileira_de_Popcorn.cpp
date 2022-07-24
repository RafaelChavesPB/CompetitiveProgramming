#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool func(int seg, int c, int taxa){
    int posV=0;
    for(int i=0; i<c; i++){
        int limite=taxa*seg;
        while(limite>=v[posV]){
            limite-=v[posV];
            posV++;
            if(posV==v.size()){
                return true;
            }
        }
    
    }
    return false;
}

int main(){
    int n,c,taxa,temp, alto=1024,baixo=1,meio;
    int ans;
    cin>>n>>c>>taxa;
    while(n--){
        scanf("%d",&temp);
        v.push_back(temp);
    }
    while(!func(alto,c,taxa)){
        baixo=alto;
        alto*=2;
    }
    while(!func(baixo,c,taxa)){
        meio=(alto+baixo)/2;
        if(func(meio,c,taxa)){
            alto=meio;
        }else{
            baixo=meio+1;
        }
    }
    cout<<baixo<<"\n";
    return 0;
}