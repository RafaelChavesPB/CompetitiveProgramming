#include<bits/stdc++.h>
#define pi pair<int,int>
#define ppi pair<pi,int>
#define f first
#define s second
#define x first
#define y second

using namespace  std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<string> matriz;
bool visitado[12][12][3];

queue<vector<pi>> fila;
queue<int> cont;

bool inGrid(pi p, int n){
    if(p.x<n and p.y<n and p.x>=0 and p.y>=0)
    {
        return true;
    }
    return false;
}

bool isEmpty(pi p){
    if(matriz[p.y][p.x]=='#'){
        return false;
    }
    return true;
}

bool chegou(vector<pi> p){
    for(auto it:p){
        if(matriz[it.y][it.x]!='X'){
            return false;
        }
    }
    return true;
}

bool atualizarPosicao(vector<pi> &p, int dir, int n){
    vector<pi> temp(3);
    bool confirma=true;
    int cont=0;
    for(int i=0;i<3;i++){
        temp[i]=p[i];
        temp[i].x+=dx[dir];
        temp[i].y+=dy[dir];
        
        if(inGrid(temp[i], n) and isEmpty(temp[i])){
            if(visitado[temp[i].y][temp[i].x][i]){
                confirma=false;
            }
        }else{ 
            cont++;
            temp[i]=p[i];
            if(cont==3){
                confirma=false;
            }
        }
    }
    if((temp[0]!=temp[1] and temp[0]!=temp[2] and temp[1]!=temp[2])){
        p=temp;
    }else{
        if(temp[0]==temp[1]){
            temp[0]=p[0];
            temp[1]=p[1];
        }
        if(temp[2]==temp[1]){
            temp[2]=p[2];
            temp[1]=p[1];
        }
        if(temp[2]==temp[0]){
            temp[2]=p[2];
            temp[0]=p[0];
        }
        p=temp;
    }
    return confirma;
}

int bfs(int n,vector<pi> coord){
    vector<pi> temp=coord;
    int contador;
    fila.push(temp);
    cont.push(0);
    while(!fila.empty()){
        temp=fila.front();
        contador=cont.front();
        fila.pop();cont.pop();
        if(chegou(temp)){
            return contador;
        }
        visitado[temp[0].y][temp[0].x][0]=true;
        visitado[temp[1].y][temp[1].x][1]=true;
        visitado[temp[2].y][temp[2].x][2]=true;
        for(int i=0; i<4;i++){
            vector<pi> provisorio=temp;
            if(atualizarPosicao(provisorio,i,n)){
                fila.push(provisorio);
                cont.push(contador+1);
            /*
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        bool flag=true;
                        for(int k=0;k<3;k++){
                            if(provisorio[k].x==j and provisorio[k].y==i)
                            {    
                                cout<<k+1<<" ";
                                flag=false;
                                break;
                            }                        
                        }
                        if(flag)
                            cout<<matriz[i][j]<<" ";
                    } 
                    cout<<endl;
                }
                cout<<provisorio[0].x <<" "<<provisorio[0].y<<" // "<<provisorio[1].x <<" "<<provisorio[1].y<<" // "<<provisorio[2].x <<" "<<provisorio[2].y<<endl;
                cout<<"\n"<<contador<<endl;
            
            */
            }
        }
        // int b;
        // cin>>b;
        for(int k=0;k<3;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<visitado[i][j][k]<<" ";
                }
                cout<<endl;
            } 
            cout<<endl;
        }
    }
    return -1;
}

int main(){
    int tam, n;
    int caso=1;
    string temp;
    vector<pi> coord(3);
    scanf("%d",&n);
    while(n--){
        memset(visitado,false,sizeof(visitado));
        matriz.clear();
        scanf("%d",&tam);
        for(int i=0;i<tam;i++){
            cin>>temp;
            matriz.push_back(temp);
            for(int j=0;j<tam;j++){
                switch (matriz[i][j]){
                case 'A':
                    coord[0].x=j;
                    coord[0].y=i;
                    matriz[i][j]='.';
                    
                    break;
                case 'B':
                    coord[1].x=j;
                    coord[1].y=i;
                    matriz[i][j]='.';
                    break;
                case 'C':
                    coord[2].x=j;
                    coord[2].y=i;
                    matriz[i][j]='.';
                    break;
                
                // case '#':
                //     visitado[i][j][0]=true;
                //     visitado[i][j][1]=true;
                //     visitado[i][j][2]=true;
                }
            }
        }

       
        int ans=bfs(tam, coord);

        

        cout<<"Case "<<caso++<<": ";
        if(ans>=0){
            cout<<ans<<endl;
        }else{
            cout<<"trapped"<<endl;
        }
    }
    return 0;
}