void coinChangeDP3()
{
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            dp[i][j] = (i - 1 >= 0) ? dp[i - 1][j] : INF;
            if (j - coins[i] >= 0)
            {
                
                dp[i][j] = min(dp[i][j],1+dp[i][j-coins[i]]);
            }
        }
    }
}


//O(n) = numberCoins*MAX =  3*12 = 