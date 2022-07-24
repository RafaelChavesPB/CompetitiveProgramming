#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v('z' - 'a' + 1, 0);
    string s;
    int acc = 0;
    cin >> s;
    for (auto x : s)
        v[x - 'a']++;
    for (auto x : v)
        if(x % 2)
            acc++;
    if (acc == 0 or acc % 2)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}