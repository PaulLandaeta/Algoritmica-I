#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
vector<string> graph(510);
int n, m, k;
int dRow[] = {-1, 0, 1, 0};    // trick to explore an implicit 2D grid
int dColumn[] = {0, 1, 0, -1}; // S,SE,E,NE,N,NW,W,SW neighbors
int visitados[510][510];
//4 direcciones
// int drow[]    = {-1,0,1,0};
// int dcolumn[] = {0,1,0,-1};

void dfs(int row, int column)
{
    if (row < 0 || row >= n || column < 0 || column >= m || visitados[row][column])
    {
        return; // outside grid
    }

    if (graph[row][column] == '#')
    {
        return; // does not have color c1
    }

    visitados[row][column] = 1;

    for (int d = 0; d < 4; d++)
    {
        dfs(row + dRow[d], column + dColumn[d]);
    }

    if(k) {
        graph[row][column] = 'X';
        k--;
    }
}

int main()
{
    input;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.')
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << graph[i] << endl;
    }
}
