#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    vector<string> m;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string temp;
        cin >> temp;
        m.push_back(temp);
    }
    int ans=0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] != 'S')
            {
                int cont=0;
                for (int k = 0; k < c; k++)
                {
                    if(m[i][k]=='S'){
                        cont++;
                        break;
                    }
                }
                for (int k = 0; k < r; k++)
                {
                    if (m[k][j] == 'S'){
                        cont++;
                        break;
                    }
                }
                if(cont<2)
                    ans++;
            }
        }
    }


    cout<<ans<<endl;
    return 0;
}