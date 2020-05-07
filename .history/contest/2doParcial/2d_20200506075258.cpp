#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std;

long long _sieve_size;
bitset<10000010> bs; // 10^7 should be enough for most cases
vector<long long> primes;

void sieve(long long upperbound)
{                                 // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set();                     // set all bits to 1
    bs[0] = bs[1] = 0;            // except index 0 and 1
    for (long long i = 2; i < _sieve_size; i++)
        if (bs[i])
        {
            // cross out multiples of i <= _sieve_size starting from i*i
            for (long long j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i); // also add this vector containing list of primes
        }
}

int main()
{

    int x,y;
    cin>>x>>y;
    sieve(10000000);
    for(int i=x;i)
}