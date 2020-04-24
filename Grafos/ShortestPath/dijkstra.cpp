#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define SIZE 100000 + 1
#define INF 100000010

using namespace std; 

vector<pair< int , int > > v[SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];

void dijkstra(int initialNode){
    memset(dist, INF , sizeof dist);            // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[initialNode] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert(make_pair(0 , initialNode));                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( vis[x] ) {
            continue;                  // check if the popped vertex is visited before
        }
        vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int edge = v[x][i].second; 
            int weight = v[x][i].first;
            if(dist[x] + weight < dist[edge]  ){            // check if the next vertex distance could be minimized
                dist[edge] = dist[x] + weight;
                s.insert(make_pair(dist[edge],  edge) );           // insert the next vertex with the updated distance
            }
        }
    }
}

int main() {
    input;
    int n,m;
    cin>>n>>m; 
    for(int i=0;i<m;i++) {
        int a,b,peso;
        cin>>a>>b>>peso;
        v[a].push_back(make_pair(peso,b));
        v[b].push_back(make_pair(peso,a));
    }
    dijkstra(1);

    for(int i=1;i<=n;i++) {
        cout<<"["<<dist[i]<<"]";
    }    


    return 0;
}