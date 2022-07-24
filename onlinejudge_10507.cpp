#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n)
    {
        int ans = 0;
        map<char, int> wakeup;
        map<char, int> qtd;
        map<char, string> adj;
        priority_queue<pair<int, char>,vector<pair<int,char>>,greater<pair<int,char>>> fila;
        string in;
        cin >> m;
        cin >> in;
        for (auto x : in)
        {
            fila.push({0, x});
            wakeup[x] = 1;
        }
        while (m--)
        {
            cin >> in;
            adj[in[0]].push_back(in[1]);
            adj[in[1]].push_back(in[0]);
            wakeup[in[1]];
            wakeup[in[0]];
        }
        while (!fila.empty())
        {
            int ano = fila.top().first;
            char parte = fila.top().second;
            fila.pop();
            for(auto x : adj[parte]){
                if(!wakeup[x]){
                    if(++qtd[x]==3){
                        fila.push({ano+1,x});
                        wakeup[x]=1;
                        ans=ano+1;
                    }
                }
            }
        }
        string out = "WAKE UP IN, "+to_string(ans)+", YEARS";
        if(wakeup.size()<n)
                out ="THIS BRAIN NEVER WAKES UP";
        for(auto x: wakeup){
            if(x.second==0){
                out ="THIS BRAIN NEVER WAKES UP";
            }
        }
        cout<<out<<endl;
    }
    return 0;
}