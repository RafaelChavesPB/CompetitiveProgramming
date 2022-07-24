#include <bits/stdc++.h>
using namespace std;

long long h1 = 3600*1e9;
long long h2 = 60*1e9;
long long h3 = 1e9;
long long m1 = 720*1e9;
long long m2 = 12*1e9;
long long s1 = 720*1e9;

array<long long,4> timeTransforms(string tipo, long long in){
    array<long long,4> out;
    if(tipo == "h"){
        out[0]=in/(h1);
        in%=h1;
        out[1]=in/(h2);
        in%=h2;
        out[2]=in/(h3);
        out[3]=in%h3;
    }else if(tipo == "m"){
        out[0]=0;
        out[1]=in/(m1);
        in%=m1;
        out[2]=in/(m2);
        out[3]=in%m2;
    }else if(tipo == "s"){
        out[0]=0;
        out[1]=0;
        out[2]=in/(s1);
        out[3]=in%(s1);
    }
    return out;
}

typedef struct time_{
    array<long long,4> hours,minutes,seconds;
    time_(long long ticks){
        hours = timeTransforms("h",ticks);
        minutes = timeTransforms("m",ticks);
        seconds = timeTransforms("s",ticks);
    }
} Time;

bool compare(vector<int> seq, vector<Time> v){
    for(int i=1;i<3;i++){
        if(v[seq[0]].hours[i]!=v[seq[1]].minutes[i])
            return false;
    }
    for(int i=2;i<4;i++){
        if(v[seq[0]].hours[i]!=v[seq[2]].seconds[i] or v[seq[1]].minutes[i]!=v[seq[2]].seconds[i])
            return false;
    }
    return true;
}

void print(Time A){
    cout<<"Horas"<<endl;
    for(int i=0;i<4;i++){
        cout<<A.hours[i]<<' ';
    }
    cout<<endl;
    cout<<"Minutos"<<endl;
    for(int i=0;i<4;i++){
        cout<<A.minutes[i]<<' ';
    }
    cout<<endl;
    cout<<"segundos"<<endl;
    for(int i=0;i<4;i++){
        cout<<A.seconds[i]<<' ';
    }
    cout<<endl;

}

int main(){
    int cases,t;
    cin>>cases;
    for(long long t=1;t<=cases;t++){
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<"Case #"<<t<<": ";
        bool flag=true;
        for(long long i=min(a,min(b,c));i>=0;i-=1e9){
            Time A(a-i),B(b-i),C(c-i);
            vector<Time> v={A,B,C};
            vector<int> seq={0,1,2};
            do{
                if(compare(seq,v)){
                    flag=false;
                    for(int i=0;i<4;i++){
                        cout<<v[seq[0]].hours[i]<<' ';
                    }
                    cout<<endl;
                    for(auto it:v){
                        print(it);
                        cout<<endl;
                    }
                    cout<<endl<<endl<<i<<endl;
                    break;
                }
            }while(next_permutation(seq.begin(),seq.end()));
            if(!flag)
                break;
    
        }
        
    }
    return 0;
}