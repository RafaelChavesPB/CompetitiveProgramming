#include <bits/stdc++.h>

using namespace std;

void func(vector<vector<int>> m, vector<int> c, int v)
{
    if (c.size() == 9)
    {
        for (auto i : c)
            cout << i;
        cout << endl;
        return;
    }

    for (int i=1; i<6; i++){
        
        if(m[min(i,v)][max(i,v)]){
            c.push_back(i);
            m[min(i,v)][max(i,v)]=0;
            func(m,c,i); 
            c.pop_back();
            m[min(i,v)][max(i,v)]=1;
        }
    }
}

int main()
{
    vector<vector<int>> m(6, vector<int>(6, 0));
    m[1][2] = m[1][3] = m[1][5] = m[2][3] = m[2][5] = m[3][4] = m[3][5] = m[4][5] = 1;
        func(m,vector<int>()={1},1);

    return 0;
}