#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, temp ;
    cin >> t;
    while(t--){
        map<int,int> mp;
        vector<int> v;
        pair<int,int> ans(0,0);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin>>temp;
            mp[temp]++;
            v.push_back(temp);
        } 
        for( int s = 2; s <= 2 * n; s ++ ){
            map<int,int> test = mp;
            int qtd = 0;
            for(auto i : v){
                if(test[i]>0){
                    test[i]--;
                    if(test[s-i]>0){
                        test[s-i]--;
                        qtd++;
                    }
                }
            }
            ans = max(ans, make_pair(qtd,s));
        }
        cout<<ans.first<<endl;
    }
    return 0;
}