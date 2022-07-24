#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> s(n + 1), sfa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sfa[i] = sfa[i - 1] + s[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int a = sfa[i];
        for(int j = i + 1; j <= n; j++){
            int b = (j - i) - (sfa[j] - sfa[i]) + (sfa[n] - sfa[j]);
            ans = max(ans, a + b);
        }
    }
    cout<<ans<<endl;
    return 0;
}