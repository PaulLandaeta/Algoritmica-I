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

long long fact(long long n, long long x)
{
    long long factorial = 1;
    for (long long i = 1; i < n; i++)
    {
        factorial = (factorial % x * i % x) % x;
    }
    return factorial;
}

int main()
{
    input;
    long long n
    cin >> n ;

    //cout<<modulo(n,m,x);
   long long factorial = fact(n,x);
    cout << result << endl;
}