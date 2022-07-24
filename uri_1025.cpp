#include<iostream>
#include<vector>
#include<algorithm>
#define BEGIN list_marbles.begin()
#define END list_marbles.end()

using namespace std;

int main (){
    
    int q_queries;
    int q_marbles;
    int marble_value;
    int pos;
    vector<int> list_marbles;
    ios::sync_with_stdio(false);

    for(int case_number=1;case_number<65;case_number++)
    {    
        cin>>q_marbles>>q_queries;
        
        if(q_marbles==0&&q_queries==0)
            break;

        cout<<"CASE# "<<case_number<<":"<<"\n";

        for(int i=0;i<q_marbles;i++)
        {    
            cin>>marble_value;
            list_marbles.push_back(marble_value);
        }

        sort(BEGIN,END);

        for(int i=0;i<q_queries;i++)
        {
            cin>>marble_value;
            //pos=lower_bound(BEGIN,END,marble_value)-BEGIN;
            if((*lower_bound(BEGIN,END,marble_value))==marble_value)
                cout<<marble_value<<" found at "<<pos+1<<"\n";
            else
                cout<<marble_value<<" not found"<<"\n";
        }

        list_marbles.clear();
    }
}