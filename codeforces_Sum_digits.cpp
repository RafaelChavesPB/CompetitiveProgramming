#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    if (s.size() == 1)
        return 0;
    long long sum = 0;
    for (auto x : s)    
        sum += x-'0';
    return solve(to_string(sum)) + 1;
}

int main()
{
    string input;
    cin >> input;
    cout<<solve(input)<<endl;
    return 0;
}