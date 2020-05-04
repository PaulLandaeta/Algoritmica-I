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

vector<long long> factoresPrimos(long long number)
{ // 24
    vector<long long> factores;
    int i = 0;
    while (number != 1)  // 1234567890 
    {
        int primo = primes[i]; // 2, 3
        while (number % primo == 0)
        {                              // 24%2  12%2 6%2 3%2 3%3 1%3
            number = number / primo;   // 24/2 = 12/2 = 6/2 = 3/3 = 1
            factores.push_back(primo); // [2][2][2][3]
        }
        i++;
    }
    // i< = sqrt(n)   // ()^2
    // i^2 <= (sqrt(n))^2   i * i <= n

    return factores;
}

int main()
{
    input;
    int number;
    cin >> number;
    sieve(number);
    vector<long long> factores = factoresPrimos(number);
    for (int i = 0; i < factores.size(); i++)
    {
        cout << "[" << factores[i] << "]";
    }
    cout << endl;
}