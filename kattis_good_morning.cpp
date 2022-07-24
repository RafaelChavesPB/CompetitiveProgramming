#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> m= {{1,2,3},
                        {4,5,6},
                        {7,8,9},
                        {-1,0,-1}};

int func(int l,int c, int k, vector<int> v){
    if(v.size()==3){
        return v[0]*100+v[1]*10+v[2];
    }

    int melhor=0;
    int atual;
    int dif=10000;

    for(int i=l;i<4;i++){
        for(int j=c;j<3;j++){
            if(m[i][j]>-1){
                v.push_back(m[i][j]);
                atual=func(i,j,k,v);
                v.pop_back();
                if(abs(k-atual)<dif){
                    melhor=atual;
                    dif=abs(k-atual);
                }
            }
        }
    }

    return melhor;

}

int main(){
    int n, k;
    cin>>n;
    while(n--){
        cin>>k;
        
        auto a=func(0,0,k,vector<int>());
        auto b=func(0,0,k,vector<int>(1,0));
        auto c=func(0,0,k,vector<int>(2,0));
        auto dif_a=abs(a-k);
        auto dif_b=abs(b-k);
        auto dif_c=abs(c-k);

        if(dif_a<dif_b and dif_a<dif_c){
            cout<<a<<endl;
        }else if(dif_b<dif_a and dif_b<dif_c){
            cout<<b<<endl;
        }else{
            cout<<c<<endl;
        }
        
    }

    return 0;
}