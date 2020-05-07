#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std;

// Fuerza Bruta
long long fiboFB(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fiboFB(n - 1) + fiboFB(n - 2);
}

//DP 
long long fiboStore[10000000]; // setear a todos -1

long long fiboDP(long long n)
{
    if (fiboStore[n] == -1)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        fiboStore[n] = fiboDP(n - 1) + fiboDP(n - 2);///caching store almacenar 
    }
    return fiboStore[n];
}

// 0 1 1 2 3 5 8 13 21 ...... 
// hallar fibo n y n <1000000
long long fiboDP2(long long n) {
    // base case 
    fiboStore[0]= 0;
    fiboStore[1]= 1;
    for(int i = 2;i<=n; i++){
        fiboStore[i] = fiboStore[i-1]+ fiboStore[i-2];
    }
    return fiboStore[n];
}

int main()
{
    input;
    int n;
    cin >> n;
    memset(fiboStore, -1, sizeof(fiboStore));
    cout << fiboDP(n) << endl;
    //cout << fiboDP(n) << endl;
}