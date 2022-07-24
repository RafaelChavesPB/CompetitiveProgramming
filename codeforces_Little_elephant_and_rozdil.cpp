#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp, best_id = -1, best_value = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp < best_value)
        {
            best_value = temp;
            best_id = i;
        }else if (temp == best_value)
        {
            best_id=-1;
        }
    }

    if(best_id<0){
        cout<<"Still Rozdil"<<endl;
    }else{
        cout<<best_id<<endl;
    }
    return 0;
}