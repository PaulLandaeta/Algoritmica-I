#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std;
//Fila A
//Dado 3 números N, M y X hallar el resultado de pow(N,M)%X
//donde N, M y X < 1000000000

//Fila B
//Dado 2 números N, X hallar el resultado de N!%X
//donde N, X < 10000000000

//Fila C
// Dado 3 números N, M, Y hallar el resultado de (N!/M!)%X
//donde N, M, X < 10000000000

//Fila D
//Dado 1 número N hallar el resultado de 2^N!%10000007
//donde N < 10000000000

long long modulo(long long a, long long b, long long c)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % c;
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}
// 1234345!


// a*b % mod = a%mod*b%mod 

// 14*47%3  = 658%3 = 1 
// (14%3 * 45%3)%3 = 2*
long long fact(long long n, long long x)
{
    int multiplo = -1;
    long long factorial = 1;
    for (long long i = 1; i <= n; i++)
    {
        if (factorial == 0)
        {
            multiplo = i;
        }
        factorial = (factorial % x * i % x) % x;
    }
    cout << "en esta posicion se queda 0-> " << multiplo << endl;
    return factorial;
}

int main()
{
    input;
    long long n;
    cin >> n;
    long long x = 10000007;
    //cout<<modulo(n,m,x);
    long long factorial = fact(n, x);
    cout << factorial << endl;
    cout << modulo(2, factorial, x) << endl;
}