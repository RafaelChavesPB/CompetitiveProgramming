#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> diff;
    string a, b, ans="NO";
    cin >> a >> b;
    if(a.size() == b.size()){
        for (size_t i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                diff.push_back(i);
        if(a==b or diff.size() == 2){
            swap(a[diff[0]],a[diff[1]]);
            if(a==b)
                ans="YES";
        }
    }
    cout<<ans<<endl;

    return 0;
}