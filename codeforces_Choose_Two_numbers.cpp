    #include <bits/stdc++.h>
     
    using namespace std;
     
    vector<int> A,B;
     
    void encontra(){
        int sum;
        for(auto a: A){
            for(auto b: B){
                sum=a+b;
                if(find(A.begin(),A.end(),sum)==A.end()&&find(B.begin(),B.end(),sum)==B.end()){
                    cout<<a<<" "<<b<<"\n";
                    return ;
                }
            }
        }
    }
     
    int main(){
        int temp;
        int q;
     
        cin>>q;
        while(q--){
            cin>>temp;
            A.push_back(temp);
        }
        cin>>q;
        while(q--){
            cin>>temp;
            B.push_back(temp);
        }
     
        encontra();
    }