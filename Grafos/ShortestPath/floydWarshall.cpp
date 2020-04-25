#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define SIZE 100000 + 1
#define INF 10000000

using namespace std; 

int n,m;
int graph[501][501];



void floydWarshall(){
    for(int pivot = 1; pivot<= n ; pivot++){
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(graph[i][pivot]!=INF && graph[pivot][j]!=INF) {
                    graph[i][j] = min(graph[i][j],(graph[i][pivot]+graph[pivot][j]));
                }
                
            }
        }
    }
}

int main() {
    input;
    cin>>n>>m;
    memset(graph,-1,sizeof(graph));
    for(int i = 0 ; i < m; i++) {
        int node1,node2,weight; 
        cin>>node1>>node2>>weight;
        graph[node1][node2] = weight;
    }

     for(int i=1;i<=n;i++) {
        for(int j =1; j <= n ;j++ ) {
          if(i==j) 
          graph[i][j]=0;
          else{
              if(graph[i][j]==-1){
                  graph[i][j] = INF;
              }
          }
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++) {
        for(int j =1; j <= n ;j++ ) {
            cout<<"[" <<graph[i][j]<<"]";
        }
        cout<<endl;
    }


    floydWarshall();
    ///
    cout<<"=============================="<<endl;
    for(int i=1;i<=n;i++) {
        for(int j =1; j <= n ;j++ ) {
            cout<<"[" <<graph[i][j]<<"]";
        }
        cout<<endl;
    }

    return 0;
}