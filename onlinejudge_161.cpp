#include <bits/stdc++.h>
using namespace std;

string encode(int num){
    if(num<10)
       return "0"+to_string(num);
    return to_string(num);
}

string to_hour(int num){
    string ans;
    ans+=encode(num/3600)+':';
    num%=3600;
    ans+=encode(num/60)+':';
    num%=60;
    ans+=encode(num);
    return ans;
}

int main()
{
    int num;
    while (cin >> num, num)
    {
        int menor=num;
        vector<vector<pair<int, int>>> lista;
        vector<pair<int, int>> ans, aux;
        while (num)
        {
            menor=min(num,menor);
            lista.push_back(vector<pair<int, int>>());
            for (int i = 0; i <= 18000; i += 2 * num)
                lista.back().push_back({i, min(i + num - 6,18000)});
            cin>>num;
        }
        ans = lista.front();
        lista.front().front().first = menor;
        for (auto v : lista)
        {
            for (auto p : ans)
            {
                auto next = upper_bound(v.begin(), v.end(),make_pair(p.first,0));
                if (next == v.end())
                {
                    auto earlier = next - 1;
                    pair<int,int> candidate = {max(p.first, earlier->first), min(p.second, earlier->second)};
                    if(candidate.first<=candidate.second){
                        aux.push_back(candidate);
                    }
                }
                else if( next == v.begin())
                {
                    pair<int,int> candidate = {max(p.first, next->first), min(p.second, next->second)};
                    if(candidate.first<=candidate.second){
                        aux.push_back(candidate);
                    }
                }else{
                    
                    pair<int,int> candidate = {max(p.first, next->first), min(p.second, next->second)};
                    if(candidate.first<=candidate.second)
                        aux.push_back(candidate);
                    
                    auto earlier = next - 1;
                    candidate = {max(p.first, earlier->first), min(p.second, earlier->second)};
                    if(candidate.first<=candidate.second)
                        aux.push_back(candidate);
                    
                }
            }
            swap(aux, ans);
            aux.clear();
        }
        if(ans.size()){
            cout<<to_hour(ans.front().first)<<endl;
        }else{
            cout<<"Signals fail to synchronise in 5 hours"<<endl;
        }

    }
}