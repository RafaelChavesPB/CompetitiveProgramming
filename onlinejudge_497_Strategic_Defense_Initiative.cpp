#include <bits/stdc++.h>
using namespace std;

vector<int> memory;
vector<int> ligacoes;
vector<int> seq;

set<int> maiorseq;

int lis(int n){
    int res, max_ending_here=1;
    if(n==1){
        memory[0]=1;
        return 1;
    }
    if(memory[n-1]){
        return memory[n-1];
    }
    for(int i=1;i<n;i++){
        res=lis(i);
        if(seq[i-1]<seq[n-1]&&res+1>max_ending_here){
            max_ending_here=res+1;
            ligacoes[n-1]=i-1;
        }
    }

    memory[n-1]=max_ending_here;

    return max_ending_here;
}

int _lis(int n){
    int maior=INT_MIN;
    int pos=0;

    for(int i=0;i<n;i++){
        memory[i]=0;
        ligacoes[i]=-1;
    }

    lis(n);

    for(int i=0;i<n;i++){
        if(memory[i]>maior){
            maior=memory[i];
            pos=i;

        }
    }
    while(true){
        maiorseq.insert(seq[pos]);
        if(ligacoes[pos]<0){
            break;
        }
        pos=ligacoes[pos];
    }

    return maior;
}

int main(){

    int temp, cases;
    string str;

    cin>>cases;
    cin.ignore();
    cin.ignore();
    
    while(cases--){
        
        while(getline(cin,str)&&str!=""){
            temp=atoi(str.c_str());
            seq.push_back(temp);
            ligacoes.push_back(-1);
            memory.push_back(-1);
        }

        cout<<"Max hits:"<<" "<<_lis(seq.size())<<endl;
        
        for(auto x: maiorseq){
            cout<<x<<"\n";
        }
        if(cases)
            cout<<"\n";    
        seq.clear(),ligacoes.clear(), memory.clear(), maiorseq.clear();
    }
    
    

    return 0;
}