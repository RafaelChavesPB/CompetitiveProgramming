#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, temp;
    vector<int> v;
    cin >> n;
    while (n--){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    swap(v.back() ,v.front());
    for (auto i : v){
        cout << i << ' ';
    }
    cout<<endl;
    return 0;
}