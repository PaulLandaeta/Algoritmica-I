#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define INF 1000000000
#define MAX 7490
using namespace std;

int entry[5] = {1, 5, 10, 25, 50};
long long dp[MAX][MAX];

void coinChangeDP2()
{

    for (int i = 0; i < 5; i++)
    {
        for (int T = 0; T < MAX; T++)
        {
            if (T == 0)
            {
                dp[i][T] = 1;
            }
            else
            {
                if (T - entry[i] >= 0)
                {
                    dp[i][T] = (i - 1 >= 0) ? dp[i - 1][T] : 0;
                    dp[i][T] += dp[i][T - entry[i]];
                }
                else
                {
                    dp[i][T] = (i - 1 >= 0) ? dp[i - 1][T] : 0;
                }
            }
        }
    }
}

int main()
{
    input;
    long long T;
    coinChangeDP2();
    while (cin >> T)
    {
        cout << dp[4][T] << endl;
    }
}
