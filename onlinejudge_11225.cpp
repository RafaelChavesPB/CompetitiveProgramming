#include <bits/stdc++.h>
using namespace std;
int oudlers;
bool is_oudlers(pair<string,string> &card)
{
    if ((card.first== "twenty-one" or card.first=="one") and card.second=="trumps"  or card.first=="fool")
    {
        oudlers++;
        return true;
    }
    return false;
}
int points(pair<string,string> &card)
{
    if (is_oudlers(card) or card.first=="king")
        return 4;

    if (card.first=="queen")
        return 3;

    if (card.first=="knight")
        return 2;

    if (card.first=="jack")
        return 1;

    return 0;
}
int main()
{
    int t, n, pont,goal,cont=1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin.ignore();
        oudlers = 0;
        pont = n / 2;
        string a,b,c;
        while (n--)
        {
            pair<string,string> card;
            cin>>a;
            card.first=a;
            if(a!="fool"){
                cin>>b>>c;
                card.second=c;
            }
            pont += points(card);
        }
        switch (oudlers)
        {
        case 3:
            goal = 36;
            break;
        case 2:
            goal = 41;
            break;
        case 1:
            goal = 51;
            break;
        case 0:
            goal = 56;
        }
        cout<<"Hand #"<<cont++<<endl;
        if(pont>=goal){
            cout<<"Game won by "<<pont-goal<<" point(s)."<<endl;
        }else{
            cout<<"Game lost by "<<goal-pont<<" point(s)."<<endl;
        }
        if(t)
            cout<<endl;
    }
    return 0;
}