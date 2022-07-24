#include <bits/stdc++.h>

using namespace std;

double area(double a, double b, double c)
{
    auto p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
    int n;
    vector<long long> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        v.push_back(0);
        cin >> v.back();
    }

    sort(v.begin(), v.end(), greater<long long>());

    for (int i = 0; i < n; i++)
    
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (v[i] < v[j] + v[k] and abs(v[j] - v[k]) < v[i] and v[j] < v[i] + v[k] and abs(v[i] - v[k]) < v[j] and abs(v[j] - v[i]) < v[k] and v[k] < v[j] + v[i])
                {
                    cout << v[k] << " " << v[j] << " " << v[i] << endl;
                    return 0;
                }
    
    return 0;
}