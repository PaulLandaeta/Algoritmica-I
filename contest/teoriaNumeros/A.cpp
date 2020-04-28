#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool isPrime(int number)
{
    int cont = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
        return true;
    return false;
}

int main()
{
    input;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long m, n;
        cin >> m >> n;
        for (int i = m; i <= n; i++)
        {
            if (isPrime(i))
                cout << i << endl;
        }
        cout << endl;
    }
}