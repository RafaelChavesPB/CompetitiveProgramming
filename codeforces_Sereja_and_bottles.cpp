#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<pair<int, int>, int>> bottles;
    int n, a, b;
    cin >> n;
    int ans = n; 
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        bottles.push_back({{a, b}, 1});
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j and bottles[i].first.second == bottles[j].first.first and bottles[j].second){
                bottles[j].second = 0;
                ans--;
            }
    
    cout << ans << endl;
}