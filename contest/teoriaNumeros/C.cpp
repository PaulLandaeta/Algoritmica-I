#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool isPrime(int n)
{
    int i;
    int sqrtN = sqrt(n);
    if (n < 2)
        return 0;
    for (i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    input;
    long long number, result;
    while (scanf("%lld", &number) == 1 && number)
    {
        bool isPrimeNumber = isPrime(number);
        if (isPrimeNumber)
        {

            // 1<<number pow(2,number)
            // 1<<(number-1) pow(2,number-1)
            result = (1 << number) - 1;
            if (isPrime(result))
            {
                printf("Perfect: %lld!\n", (1 << (number - 1)) * result);
            }
            else
            {
                printf("Given number is prime. But, NO perfect number is available.\n");
            }
        }
        else
        {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
}