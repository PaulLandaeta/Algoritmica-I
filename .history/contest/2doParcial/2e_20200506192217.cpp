#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector<long long> primes;

void sieve(long long upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i < _sieve_size; i++)
        if (bs[i])
        {

            for (long long j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

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
    long long n, m, x;
    cin >> n >> m >> x;

    //(a*b)%x  ==  (a%x*b%x)%x
     long long result = pow(n, m);
   // result %= x;
    cout << result << endl;
    cout << modulo(n, m, x) << endl;
}

long long factorial(long long n, long long x) {
    if(n==0)
        return 1;
    return n*factorial(n-1,x);
}

long long factorial2(long long n,long long x) {
    long long factResult= 1;
    while(n>0) {
        factResult = (factResult * n )%x;
    }
}

