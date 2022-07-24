#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,cont=1;
    cin>>t;
    while(t--){
        deque<string> pile;
        deque<string> hand;
        int y=0,x;
        for(int i=0;i<52;i++){
            string a;
            cin>>a;
            if(i<27)
                pile.push_back(a);
            else 
                hand.push_back(a);
        }         
        for(int i=0;i<3;i++){
            string atual=pile.back();
            pile.pop_back();
            if(isdigit(atual[1])){
                x=(atual[1]-'0');
                y+=x;
                int j=10-x;
                while(j--){
                    pile.pop_back();
                }
            }else{
                y+=10;
            }
        }
        pile.insert(pile.end(),hand.begin(),hand.end()-1);
        cout<<"Case "<<cont++<<": "<<pile[y-1]<<endl;
    }
    return 0;
}