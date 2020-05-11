#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1010
using namespace std;

string v, w;
int vLength;
int wLength;
int dp[MAX][MAX];
int f(int i, int j)
{
    if (i >= vLength || j >= wLength)
    {
        return 0;
    }
    if (v[i] == w[j])
    {
        return 1 + f(i + 1, j + 1);
    }
    else
    {
        return max(f(i + 1, j), f(i, j + 1));
    }
}

int fDP1(int i, int j)
{
    if (i >= vLength || j >= wLength)
    {
        return 0;
    }
    if (dp[i][j] == -1)
    {
        if (v[i] == w[j])
        {
            dp[i][j] = 1 + fDP1(i + 1, j + 1);
        }
        else
        {
            dp[i][j] = max(fDP1(i + 1, j), fDP1(i, j + 1));
        }
    }
    return dp[i][j];
}

void fDP2()
{
    for (int i = 1; i <= vLength; i++)
    {
        for (int j = 1; j <= wLength; j++)
        {
            if (v[i - 1] == w[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main()
{
    input;
    std::ios::sync_with_stdio(false);
    while (getline(cin,v))
    {
        getline(cin,w);
        vLength = v.length();
        wLength = w.length();
        memset(dp, 0, sizeof(dp));
        fDP2();
        cout << dp[vLength][wLength] << endl;
    }
    return 0;
}