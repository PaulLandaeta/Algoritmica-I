#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

#define SIZE 20010
#define INF 100000010

using namespace std;

vector<pair<int, int> > grafo[SIZE];
int dist[SIZE];
int N, n, m, S, T, server1, server2, w;
int cases = 1;

void dijkstra(int initialNode)
{
    memset(dist, INF, sizeof dist);
    dist[initialNode] = 0;
    multiset<pair<int, int> > s;
    s.insert(make_pair(0, initialNode));
    while (!s.empty())
    {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        int x = p.second;
        int wei = p.first;
        if (dist[x] < wei)
        {
            continue;
        }
        for (int i = 0; i < grafo[x].size(); i++)
        {
            int edge = grafo[x][i].second;
            int weight = grafo[x][i].first;
            if (dist[x] + weight < dist[edge])
            {
                dist[edge] = dist[x] + weight;
                s.insert(make_pair(dist[edge], edge));
            }
        }
    }
}

int main()
{
    input;
    cin >> N;
    while (N--)
    {
        cin >> n >> m >> S >> T;
        for(int i=0;i<SIZE;i++) {
            grafo[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            cin >> server1 >> server2 >> w;
            grafo[server1].push_back(make_pair(w, server2));
            grafo[server2].push_back(make_pair(w, server1));
        }
        dijkstra(S);
        if (dist[T] >= INF)
        {
            cout << "Case #" << cases++ << ": unreachable" << endl;
        }
        else
        {
            cout << "Case #" << cases++ << ": " << dist[T] << endl;
        }
    }
}