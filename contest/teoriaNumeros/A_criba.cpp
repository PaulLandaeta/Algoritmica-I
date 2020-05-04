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
    _sieve_size = upperbound + 1; // 101  add 1 to include upperbound
    bs.set(); /// array o matriz                     // set all bits to 1
    bs[0] = bs[1] = 0;            // except index 0 and 1
    for (long long i = 2; i < _sieve_size; i++){
        if (bs[i])    // bs[i] no es multiplo de los anteriores 
        {
            // cross out multiples of i <= _sieve_size starting from i*i
            for (long long j = i * i; j < _sieve_size; j += i)   // i = 2    j = 4  j=4+2 6 j = 6 +2 
                bs[j] = 0;
            primes.push_back(i); //  2 3  5 7 also add this vector containing list of primes
        }
    }
}

void floyd( ){
    int nodoActual = 0;
    for (int pivote = nodoActual; pivote<n;pivote++ ) {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++)  {
                graph[i][j] = min( graph[pivote][j]+graph[i][pivote],graph[i][j]);
            }
        }
    }
}



// i = 3 j = 9  j =9 +3 j =12 +3 

int main()
{
    //input;
    sieve(100000000);
    // int t;
    //cin >> t;
    for(int i = 0;i<primes.size();i++) 
        cout<<primes[i]<<endl;
    /*    
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
    */
}