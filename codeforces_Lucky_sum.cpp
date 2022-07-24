#include <bits/stdc++.h>
using namespace std;

vector<long long> ln(1, 0);

void rec(long long n, long long pot)
{
    if (pot > 9)
        return;
    long long a = pow(10, pot) * 7 + n;
    long long b = pow(10, pot) * 4 + n;
    ln.push_back(a);
    ln.push_back(b);
    rec(a, pot + 1);
    rec(b, pot + 1);
    return;
}
int main()
{
    rec(0, 0);
    sort(ln.begin(), ln.end());
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    for (long long i = 0; i < ln.size() - 1; i++)
    {
        if (ln[i] > r)
            break;
        else if (ln[i] < l and r <= ln[i + 1])
            ans += ln[i + 1] * (r - l + 1);
        else if (l < ln[i] and ln[i + 1] <= r)
            ans += ln[i + 1] * (ln[i + 1] - ln[i]);
        else if (l <= ln[i + 1] and ln[i + 1] <= r)
            ans += ln[i + 1] * (ln[i + 1] - l + (ln[i] < l));
        else if (l <= ln[i] and ln[i] < r)
            ans += ln[i + 1] * (r - ln[i]);
    }
    cout << ans << endl;
    return 0;
}