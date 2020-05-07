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
long long factorial(long long n, long long x)
{
    if (n == 0)
        return 1;

    n = 
    long long fac = n%x; 

    return (fac*factorial(n - 1, x));
}
int main()
{
    input;
    long long n, x;
    cin >> n >> x;
    cout<<n<<x<<endl;
    //cout<<modulo(n,m,x);
    cout << factorial(n, x) << endl;
}