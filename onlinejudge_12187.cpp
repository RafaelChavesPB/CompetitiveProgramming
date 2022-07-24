#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, r, c, k;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (cin >> n >> r >> c >> k, n and r and c and k)
    {
        vector<vector<int>> atual, ant;
        atual = ant = vector<vector<int>>(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> atual[i][j];
            }
        }
        while (k--)
        {
            ant=atual;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int a = i + dir[k].first;
                        int b = j + dir[k].second;
                        if (a >= 0 and b >= 0 and a < r and b < c and ant[a][b]==(ant[i][j]+1)%n)
                        {
                            atual[a][b]=ant[i][j];
                        }
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j)
                    cout<<' ';
                cout<<atual[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}