#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;  
bool visitado[1010][1010];
int level[1010][1010];
int r,c;

void bfs(int initialRow,int initialColumn) {

    queue<pair<int,int> > queuePair;
    pair<int, int> initialCell(initialRow, initialColumn); 
    queuePair.push(initialCell);
    visitado[initialRow][initialColumn] = true;
    level[initialRow][initialColumn] = 0;
    while(!queuePair.empty()){
        pair<int,int> currentCell = queuePair.front();
        queuePair.pop();
       
        if(currentCell.first+1 < r && !visitado[currentCell.first+1][currentCell.second]){
            visitado[currentCell.first+1][currentCell.second] = true;
            pair<int, int> vecino(currentCell.first+1, currentCell.second); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }

        if(currentCell.first-1 >= 0 && !visitado[currentCell.first-1][currentCell.second]){
            visitado[currentCell.first-1][currentCell.second] = true;
            pair<int, int> vecino(currentCell.first-1, currentCell.second); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }

        if(currentCell.second+1 < c && !visitado[currentCell.first][currentCell.second+1]){
            visitado[currentCell.first][currentCell.second+1] = true;
            pair<int, int> vecino(currentCell.first, currentCell.second+1); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }

        if(currentCell.second-1 >=0 && !visitado[currentCell.first][currentCell.second-1]){
            visitado[currentCell.first][currentCell.second-1] = true;
            pair<int, int> vecino(currentCell.first, currentCell.second-1); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }
    } 

}

int main() {
    input;
    
    while(cin>>r>>c){
        if(r==0 && c==0) {
            break;
        }
        memset(visitado,0,sizeof(visitado));
        memset(level,0,sizeof(level));

        int rowsBombs; 
        cin>>rowsBombs;
        for(int j=0 ; j<rowsBombs; j++) {
            int currentRow,numberBomb;
            cin>>currentRow>>numberBomb;
            for(int i=0;i<numberBomb;i++) {
                int currentColumn; 
                cin>>currentColumn;
                visitado[currentRow][currentColumn] = true;
            }
        }   

        int initialRow, initialColumn, finalRow, finalColumn; 
        cin>>initialRow>>initialColumn>>finalRow>>finalColumn;
        bfs(initialRow,initialColumn);
        cout<<level[finalRow][finalColumn]<<endl;
    }
    return 0;
}