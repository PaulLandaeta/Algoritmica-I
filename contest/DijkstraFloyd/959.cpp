#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

#define SIZE 1009
#define INF 100000010

using namespace std;
int n, m;
int graph[SIZE][SIZE];
int dist[SIZE][SIZE];
bool vis[SIZE][SIZE];

int rows[] = {-1, 1, 0, 0};
int column[] = {0, 0, 1, -1};

void dijkstra(int initialRow, int initialColumn)
{
    // set the vertices distances as infinity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
        }
    }
    memset(vis, false, sizeof vis); // set all vertex as unvisited

    dist[initialRow][initialColumn] = graph[initialRow][initialColumn];
    multiset<pair<int, pair<int, int> > > s; // multiset do the job as a min-priority queue

    s.insert(make_pair(0, make_pair(initialRow, initialColumn))); // insert the source node with distance = 0

    while (!s.empty())
    {

        pair<int, pair<int, int > > p = *s.begin(); // pop the vertex with the minimum distance
        s.erase(s.begin());
        // get Node to save in x
        pair<int, int> x = p.second;
        // get weight save in weight
        int weight = p.first;
        if (vis[x.first][x.second])
        {
            continue; // check if the popped vertex is visited before
        }
        vis[x.first][x.second] = true;

        // tenemos 4 direcciones
        for (int i = 0; i < 4; i++)
        {
            int nextRow = x.first + rows[i];
            int nextColumn = x.second + column[i];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= m)
            {
                continue;
            }

            int nextWeight = graph[nextRow][nextColumn];
            if (dist[x.first][x.second] + nextWeight < dist[nextRow][nextColumn])
            { // check if the next vertex distance could be minimized
                dist[nextRow][nextColumn] = dist[x.first][x.second] + nextWeight;
                s.insert(make_pair(dist[nextRow][nextColumn], make_pair(nextRow, nextColumn))); // insert the next vertex with the updated distance
            }
        }
    }
}

int main()
{
    input;

    int cases;
    cin >> cases;
    while (cases--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
            }
        }
        dijkstra(0, 0);
        cout << dist[n - 1][m - 1] << endl;
    }
    return 0;
}