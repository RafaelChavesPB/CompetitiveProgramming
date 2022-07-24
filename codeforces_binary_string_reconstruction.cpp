#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n1, n2, n3;
    string s;
    cin >> t;
    while (t--)
    {
        s.clear();
        cin >> n1 >> n2 >> n3;
        if (n1)
            s += '0';
        for (int i = 0; i < n1; i++)
            s += '0';

        if (n3)
            s += '1';
        for (int i = 0; i < n3; i++)
            s += '1';

        if (n1 and n3)
            n2--;

        if (!n1 and !n3)
            s += '0';

        for (int i = 0; i < n2; i++)
            if (s.back() == '0')
                s += '1';
            else
                s += '0';

        cout << s << endl;
    }

    return 0;
}