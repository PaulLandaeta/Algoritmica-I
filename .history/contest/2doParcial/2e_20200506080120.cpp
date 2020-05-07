#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std;

//Dado 3 números N, M y X hallar el resultado de pow(N,M)%X
//donde N, M y X < 1000000000


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

int main()
{
    input;
    int n,m,x;
    cin>>n>>m>>x;
   
}