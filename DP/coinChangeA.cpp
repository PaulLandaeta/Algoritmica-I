#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 1000000000
#define MAX 10000
using namespace std;

vector<int> coins;
long long dp[MAX][MAX];
// Fuerza Bruta
long long coinChange(long long T, int position)
{
    if (T == 0)
        return 0;
    if (T < 0)
        return INF;
    long long minChange = INF;
    for (int i = 0; i < coins.size(); i++)
    {
        minChange = min(minChange, 1 + coinChange(T - coins[position], i));
    }
    return minChange;
}

// DP
long long coinChangeDP(long long T, int position)
{
    if (T < 0)
        return INF;

    if (dp[T][position] == -1)
    {
        if (T == 0)
            return 0;

        //cout << T << " " << position << endl;
        long long minChange = INF;
        for (int i = 0; i < coins.size(); i++)
        {
            //if( minChange< 1 + coinChangeDP(T-coins[position],i ))
            // coinChange (1,0) coinChange(1,1) coinChange(1,2)
            // coinChange (1,0)=> coinChange(1-1,0) coinChange(1-1,1) coinChange(1-1,2)
            //coinChange(1,1) =>  coinChange(-1,0) coinChange(-1,1) coinChange(-1,2)
            //coinChange(1,2) =>  coinChange(1-3,0) coinChange(-2,1) coinChange(-2,2)
            minChange = min(minChange, 1 + coinChangeDP(T - coins[position], i));
        }
        dp[T][position] = minChange;
        //return minChange;
    }
    return dp[T][position];
}

void cleanDP()
{
    for (int i = 0; i < 100000; i++)
        for (int j = 0; j < 100000; j++)
            dp[i][j] = -1;
}

void coinChangeDP2()
{
    for (int i = 0; i < MAX; i++)
    {
        dp[0][i] = i;
    }
    // 0 -> 012345678910
    // coins= {1,2,3}
    for (int i = 1; i < coins.size(); i++)
    { // T
        for (int T = 1; T < MAX; T++)
        {
            if (T - coins[i] >= 0)
            {
                dp[i][T] = min(dp[i - 1][T], 1 + dp[i][T - coins[i]]);
            }
            else
            {
                dp[i][T] = dp[i - 1][T];
            }
        }
    }
}

int main()
{
    input;
    int T;
    cin >> T;
    int numberCoins;
    cin >> numberCoins;
    for (int i = 0; i < numberCoins; i++)
    {
        int coinValue;
        cin >> coinValue;
        coins.push_back(coinValue);
    }
    long long minimo = INF;
    //cleanDP();
    /*memset(dp, -1, sizeof(dp));

    for (int i = 0; i < numberCoins; i++)
    {
        minimo = min(minimo, coinChangeDP(T, i));
    }
    if (minimo == INF)
        cout << "No solucion :P" << endl;
    else
    {
        cout << minimo << endl;
    }
    */

    coinChangeDP2();
    cout << dp[numberCoins - 1][T] << endl;

    return 0;
}