#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define int long long



using namespace std;

struct par
{
    int x,y;
};

bool compare(par ant, par post){
    return ant.x<post.x;
}

bool compareSec(par ant, par post){
    return ant.y<post.y;
}

 main()
{
    ios::sync_with_stdio(false);
    int dist,ton,numero;
    vector<par> v;
    struct par temp;

    cin >> numero;

    for(int i=0;i<numero;i++){

        cin >> temp.x >> temp.y;
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(int j=1;j<v.size();j++)
        if(compareSec(v[j-1],v[j]))
        {
            cout<<"N"<<"\n";
            return 0;
        }

    cout<<"S"<<"\n";
    return 0;

}
