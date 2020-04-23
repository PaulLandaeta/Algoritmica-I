#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
vector<int> grafog[30];
int level[30];
int visitados[30];

void bfs(int beg){
    memset(level,0,sizeof(level));
    memset(visitados,0,sizeof(visitados));    
    queue<int> colita; 
    int nodoActual = beg;
    visitados[nodoActual] = true; 
    colita.push(nodoActual); 
    level[nodoActual] = 0;
    while(!colita.empty()){
        int nodoActual = colita.front();
        colita.pop(); 
        for(int i=0;i<grafog[nodoActual].size();i++) {
            int nodoAVisitar = grafog[nodoActual][i];  
            if(!visitados[nodoAVisitar]) {
                colita.push(nodoAVisitar);
                visitados[nodoAVisitar] = true;
                level[nodoAVisitar] = level[nodoActual] + 1;
            }
        }
    }
}

int main(){
    input;
    int nodo;
    int edge;
    int now;
    int cas=0;
    
    while(cin>>nodo){
        for(int i=0;i<=20;i++) {
            grafog[i].clear();
        }
        
       
        for(int i=0; i<nodo; i++){
            cin>>edge; 
            grafog[1].push_back(edge);
            grafog[edge].push_back(1);
        }
        for(int i=2; i<=19; i++){
            cin>>now;
            for(int j=0; j<now; j++){
                cin>>edge; 
                grafog[i].push_back(edge);
                grafog[edge].push_back(i);
            }
        }
        
        int many;
        cin>>many;
        cas++;
        cout<<"Test Case #"<<cas<<endl;
        for(int i=0;i<many;i++){
            
            int beg;
            int end;
            cin>>beg>>end;
            bfs(beg);
            cout<<beg<<" to "<<end<<" : "<<level[end]<<endl;
        }
        
        cout<<endl;
        
        
    }
}