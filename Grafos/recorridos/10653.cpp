#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;  
int grafo[1010][1010];
bool visitado[1010][1010];
int level[1010][1010];
int rows,columns;

void bfs(int initialRow,int initialColumn) {
    // memset 


    queue<pair<int,int> > queuePair;
    pair<int, int> initialCell(initialRow, initialColumn); 
    queuePair.push(initialCell);
    visitado[initialRow][initialColumn] = true;
    level[initialRow][initialColumn] = 0;
    while(!queuePair.empty()){
        pair<int,int> currentCell = queuePair.front();
        queuePair.pop();
        // Mover hacia abajo si currentCell 0,0 visito vecino 1,0
        if(currentCell.first+1 < rows && !visitado[currentCell.first+1][currentCell.second]){
            visitado[currentCell.first+1][currentCell.second] = true;
            pair<int, int> vecino(currentCell.first+1, currentCell.second); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }
        // Mover hacia arriba si currentCell 2,3  visito 1,3
        if(currentCell.first-1 >= 0 && !visitado[currentCell.first-1][currentCell.second]){
            visitado[currentCell.first-1][currentCell.second] = true;
            pair<int, int> vecino(currentCell.first-1, currentCell.second); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }
        // Mover a la derecha si current Cell 2,2 visito 2,3
        if(currentCell.second+1 < columns && !visitado[currentCell.first][currentCell.second+1]){
            visitado[currentCell.first][currentCell.second+1] = true;
            pair<int, int> vecino(currentCell.first, currentCell.second+1); 
            queuePair.push(vecino);
            level[vecino.first][vecino.second] = level[currentCell.first][currentCell.second] + 1;
        }
         // Mover a la izq si current Cell 2,2 visito 2,1
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
    
    while(cin>>rows>>columns){
        if(rows==0 && columns==0) {
            break;
        }
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