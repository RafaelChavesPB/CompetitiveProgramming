#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
long long hanoi(int n, int orig, int dest, int temp)
{
    if (n == 1)
        return dp[n] = 1;

    if (dp[n] != -1)
        return dp[n];

    long long total = 0;
    total += hanoi(n - 1, orig, temp, dest) + hanoi(n - 1, temp, dest, orig) + 1;
    return dp[n] = total;
}

int main()
{
    dp = vector<long long>(31, -1);
    hanoi(30, 0, 1, 2);
    int n, cont = 1;
    while (cin >> n, n)
    {
        cout << "Teste " << n << endl;
        cout << dp[n] << endl;
        cout << endl;
    }

    return 0;
}