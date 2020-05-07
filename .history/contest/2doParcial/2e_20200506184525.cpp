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


long long modulo(long long N, long long M, long long X)
{
    long long x = 1, y = N;
    N*N*N*N 
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
    int n;
    cin>>n;
    if(n<MAX) {
        sieve(n);
        cout<<primes.back();

    }

}
