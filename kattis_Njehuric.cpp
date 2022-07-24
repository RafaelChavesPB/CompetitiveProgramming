#include <bits/stdc++.h>

using namespace std;

int v[5];

void print(int n){
    cout<<n<<' ';
}

int main(){
    
    for (size_t i = 0; i < 5; i++)
    {
        scanf("%d",&v[i]);
    }
    
    while(!is_sorted(v,v+5)){
        for (size_t i = 0; i < 4; i++)
        {
            if(v[i]>v[i+1]){
                int temp=v[i];
                v[i]=v[i+1];
                v[i + 1]=temp;
                for_each(v,v+5,print);
                cout<<endl;
            }
        }
    }
    return 0;
}