#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    vector<int> freq(26, 0);
    cin >> n >> s;
    for (auto c : s)
        freq[c - 'a']++;
    string ans = "-1";
    bool result = true;
    for (auto j : freq)
    {
        if (j % n)
        {
            result = false;
            break;
        }
    }
    if (result)
    {
        ans.clear();
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < freq.size(); j++)
            {
                int qtd = freq[j] / n;
                while (qtd--)
                    ans += ('a' + j);
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}