#include <bits/stdc++.h>

using namespace std;

int main(){
  stack<int> a,b;
  int n,e,mov=0, elim=0;
  cin>>e;
  n=2*e;
  for(int i=0;i<n;i++){
    a.push(0);
    cin>>a.top();
  }
  do{
    elim=0;
    while(!a.empty()){
      mov++;
      if(!b.empty() and a.top()==b.top()){
        a.pop(),b.pop();
        elim++;
      }else{
        b.push(a.top());
        a.pop();
      }
    }
    swap(a,b);
  }while(elim!=0);

  if(a.empty() and b.empty()){
    cout<<mov<<endl;
  }else{
    cout<<"impossible"<<endl;
  }
  return 0;
}