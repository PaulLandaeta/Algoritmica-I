#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;   
vector<string>  graph(30);
int n,m; 
int dRow[]    = {-1,0,1,0}; // trick to explore an implicit 2D grid
int dColumn[] = {0,1,0,-1}; // S,SE,E,NE,N,NW,W,SW neighbors

//4 direcciones 
// int drow[]    = {-1,0,1,0}; 
// int dcolumn[] = {0,1,0,-1};

bool cmp(pair<char,int> a,pair<char,int>b) {
    return (a.second > b.second) || (a.second == b.second && a.first < b.first); 
}

void dfs(int row, int column,char caracter) { 
    if (row < 0 || row >= n || column < 0 || column >= m) {
        return ; // outside grid
    } 
    if (graph[row][column] == '*' ) {
        return; // does not have color c1
    }
    if(graph[row][column] != caracter) {
        return; // no visitar al q no es del mismo caracter 
    }
    graph[row][column] = '*'; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++){
        dfs(row + dRow[d], column + dColumn[d],caracter);
    }
}

int main() {
 input;
 int cases;
 cin >> cases;
 int numberCase = 1;
 while(cases--) {
     cin>>n>>m;
     for(int i=0;i<n;i++) {
         cin>>graph[i];
     }
     vector<pair<char,int> > solution; 
     for(int i = 97; i<= 123 ;i++) {
         pair<char,int> abcedario((char)(i),0); // a 0    b 0  c 0 .... z 0
         solution.push_back(abcedario);
     }
     for(int i=0;i<n;i++) {
         for(int j=0;j<m;j++) {
             if(graph[i][j]!='*') {
                solution[graph[i][j]-'a'].second = solution[graph[i][j]-'a'].second + 1;
                dfs(i,j,graph[i][j]);
             }
         }
     }
     cout<<"World #"<<numberCase++<<endl;
     sort(solution.begin(),solution.end(),cmp);
      for(int i=0;i<27;i++) {
        if(solution[i].second == 0) 
            continue;
        cout<<solution[i].first<<": ";
        cout<<solution[i].second<<endl;
     }
 }
 return 0;    
}