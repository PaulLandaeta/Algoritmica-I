#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 10000

using namespace std;

vector<pair<int, int> > objects(MAX); /// Objectos Peso Valor
//vector<bool> visitados(MAX);         /// Vector de visitados 0 si no tomamos el objeto 1 si lo tomamos
int weight;        /// Peso de la mochila
int numberObjects; /// Número de objetos

long long mochila(int i, int currentWeight)
{
   // cout << i << " " << currentWeight << endl;
    if (i >= numberObjects)
    {             /// existe un objeto mas
        return 0; // retornar el peso de la mochila ?
    }

    if (objects[i].first > currentWeight)
    {
        return 0;
    }

    int currentObjectWeight = objects[i].first;
    int currentObjectPrice = objects[i].second;

    // estoy seleccionando el objeto
    // visitados[i] = 1;
    int priceNoVisited = mochila(i + 1, currentWeight);
    int priceVisited = currentObjectPrice + mochila(i + 1, currentWeight - currentObjectWeight);
    if (priceNoVisited > priceVisited)
    {
        //visitados[i] = false;
        return priceNoVisited;
    }
    else
    {
        //visitados[i] = true;
        return priceVisited;
    }
}

long long dp[MAX][MAX];
long long mochilaDP(int i, int currentWeight)
{
    if (i >= numberObjects)
    {             /// existe un objeto mas
        return 0; // retornar el peso de la mochila ?
    }

    if (objects[i].first > currentWeight)
    {
        return 0;
    }
    if (dp[i][currentWeight] == -1)
    {
        // memoization
        int currentObjectWeight = objects[i].first;
        int currentObjectPrice = objects[i].second;

        // estoy seleccionando el objeto
        // visitados[i] = 1;
        
        int priceNoVisited = mochilaDP(i + 1, currentWeight);
        int priceVisited = currentObjectPrice + mochilaDP(i + 1, currentWeight - currentObjectWeight);
        if (priceNoVisited > priceVisited)
        {
            //visitados[i] = false;
            dp[i][currentWeight] = priceNoVisited;
        }
        else
        {
            // visitados[i] = true;
            dp[i][currentWeight] = priceVisited;
        }
    }
    return dp[i][currentWeight];
}

int main()
{
    input;
    cin >> weight;
    cin >> numberObjects;
    for (int i = 0; i < numberObjects; i++)
    {
        int weightObject, priceObject;
        cin >> weightObject >> priceObject;
        objects[i] = make_pair(weightObject, priceObject);
    }

    memset(dp, -1, sizeof(dp));
    cout << mochila(0, weight) << endl;
}