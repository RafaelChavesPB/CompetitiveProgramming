#include <bits/stdc++.h>
using namespace std;
int main(){
    int q100 = 0, q200 = 0, n, temp;
    string ans = "NO";
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp == 100)
            q100++;
        else 
            q200++;
    }
    if(q100 % 2 == 0 and ((q100 != 0 and q200 % 2) or q200 % 2 == 0))
        ans = "YES";
    cout << ans << endl;
    return 0;
}