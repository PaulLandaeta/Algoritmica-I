#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 5000
using namespace std;
int dp[MAX][MAX];
int knapsackWeight;
int numberObjects;
vector<int> numberList;
void knapsack()
{
    for (int i = 1; i <= numberObjects; i++)
    {
        for (int K = 1; K <= knapsackWeight; K++)
        {
            if (numberList[i-1] <= K)
            {
                int weight = numberList[i-1];
                dp[i][K] = max(weight + dp[i-1][K - weight], dp[i - 1][K]);
            }
            else
            {
                dp[i][K] = dp[i - 1][K];
            }
        }
    }
}

int main()
{
    input;
    output;
    int cases;
    cin >> cases;
    cin.ignore();
    //getchar();
    while (cases--)
    {

        string numbers;
        getline(cin, numbers);
        istringstream isNumber(numbers);

        int number;
        //cin>>number;
        int totalWeight = 0;
        while (isNumber >> number)
        {
            numberList.push_back(number);
            totalWeight += number;
        }
        sort(numberList.begin(), numberList.end());
        numberObjects = numberList.size();
        if (totalWeight % 2 == 0)
        {
            knapsackWeight = totalWeight / 2;

            knapsack();
            if (dp[numberList.size()][knapsackWeight] == knapsackWeight)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }

        numberList.clear();
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}