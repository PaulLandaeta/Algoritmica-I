#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

#define SIZE 20010
#define INF 100000010

using namespace std;
int main()
{
    input;
    int number, m;
    int cases = 1;
    while (cin >> number >> m)
    {
        int banned[10];
        memset(banned, 0, sizeof banned);
        for (int i = 0; i < m; i++)
        {
            int bannedNumber;
            cin >> bannedNumber;
            banned[bannedNumber] = 1;
        }
        cout << "Case " << cases++ << ": ";
        queue<int> colita;

        int visitados[SIZE];
        memset(visitados, 0, sizeof visitados);
        int from[SIZE][2];

        for (int i = 1; i <= 9; i++)
        {
            if (visitados[i % number] == 0 && !banned[i])
            {
                visitados[i % number] = 1;
                from[i % number][0] = -1; // desde donde voy a partir
                from[i % number][1] = i;  // valor de mi digito
                colita.push(i % number);  // agregar los posibles digitos
            }
        }

        while (!colita.empty())
        {
            int currentNumber = colita.front();
            colita.pop();
            for (int i = 0; i <= 9; i++)
            {
                int nextNumber = (currentNumber * 10 + i) % number; // si la suma de todos los modulos es 0 nextNumber es multiplo
                if (visitados[nextNumber] == 0 && !banned[i])
                {
                    visitados[nextNumber] = 1;
                    from[nextNumber][0] = currentNumber; // que digito es anterior
                    from[nextNumber][1] = i;             // guardamos el digito
                    colita.push(nextNumber);
                }
            }
            // si en algun momento se visita el nodo 0 significa q es multiplo
            if (visitados[0])
            {
                break;
            }
        }

        if (visitados[0])
        {
            int lastdigit = 0;
            string result = "";
            while (lastdigit >= 0)
            {
                result = (char)(from[lastdigit][1] + '0') + result;
                lastdigit = from[lastdigit][0];
            }
            cout << result << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}