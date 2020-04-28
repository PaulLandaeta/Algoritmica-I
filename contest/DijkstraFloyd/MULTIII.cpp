#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

#define SIZE 20010
#define INF 100000010

using namespace std;

int main()
{
    input;
    int number, n;
    int cases = 1;
    while (cin >> number >> n)
    {
        int banned[n];
        for (int i = 0; i < n; i++)
        {
            cin >> banned[i];
        }
        int result = -1;
        for (int i = 1; i < 10000000; i++)
        {
            int auxNumber = number * i; // 100 200 300 400 500 ..... 100 *1000
            int isValid = true;

            while (auxNumber > 0)
            {
                int mod = auxNumber % 10;
                auxNumber = auxNumber / 10;
                for (int j = 0; j < n; j++)
                {
                    if (mod == banned[j])
                    {
                        isValid = false;
                    }
                }
            }
            if (isValid)
            {
                result = number * i;
                break;
            }
        }
        cout << "Case " << cases++ << ": " << result << endl;
    }
}