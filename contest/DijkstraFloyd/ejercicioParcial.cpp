#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define INF 10000000
#define SIZE 1000
using namespace std;
// a - b  - weight
// graph[0].pushback(1,2)   {0}-> {(1,2)}
vector<pair<int, int> > graph[SIZE];
bool visitados[SIZE];
int dist[SIZE];
void dijkstra(int initialNode)
{
    for (int i = 0; i < SIZE; i++)
    {
        dist[i] = INF;
    }

    memset(visitados, false, sizeof(visitados));
    // weight - node
    multiset<pair<int, int> > queuePriority;
    queuePriority.insert(make_pair(0, initialNode));
    dist[initialNode] = 0;

    while (!queuePriority.empty())
    {
        pair<int, int> currentPair = *queuePriority.begin();
        queuePriority.erase(queuePriority.begin());
        int currentNode = currentPair.second;
        int currentWeight = currentPair.first;

        if (visitados[currentNode])
        {
            continue;
        }

        visitados[currentNode] = true;

        for (int i = 0; i < graph[currentNode].size(); i++)
        {
            pair<int, int> nextPair = graph[currentNode][i];
            int nextNode = nextPair.first;
            int weightNode = nextPair.second;

            if (dist[currentNode] + weightNode < dist[nextNode])
            {
                dist[nextNode] = dist[currentNode] + weightNode;
                queuePriority.insert(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main()
{
    input;
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].push_back(make_pair(nodeB, weight));
    }
    dijkstra(0);
    // a b c d e f g h i j
    // 0 1 2 3 4 5 6 7 8 9
    cout << dist[7] << endl;
    return 0;
}