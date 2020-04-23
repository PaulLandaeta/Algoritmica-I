#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;   
vector<string>  graph(30);
int n; 
int dRow[]    = {1,1,0,-1,-1,-1, 0, 1}; // trick to explore an implicit 2D grid
int dColumn[] = {0,1,1, 1, 0,-1,-1,-1}; // S,SE,E,NE,N,NW,W,SW neighbors

//4 direcciones 
// int drow[]    = {-1,0,1,0}; 
// int dcolumn[] = {0,1,0,-1};

int dfs(int row, int column) { 
    if (row < 0 || row >= n || column < 0 || column >= n) {
        return 0; // outside grid
    } 
    if (graph[row][column] == '0' ) {
        return 0; // does not have color c1
    }
    graph[row][column] = '0'; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 8; d++){
        dfs(row + dRow[d], column + dColumn[d]);
    }
    return 1;
}



int main() {
    input;
    int cases=0;
    while(cin>>n) {
         for(int i=0;i<n;i++) {
             cin>>graph[i];
         }
         int cont2 = 0;
        for(int i=0;i<n;i++) {
            for(int j = 0; j<n; j++) {
                if(graph[i][j]=='1') {
                    map[graph[i][j]]++;
                   dfs(i,j);
                   cont2++;
                }
            }
        }
        cout<<"Image number "<<++cases<<" contains "<<cont2<<" war eagles."<<endl;
       
    }
    return 0;
}