#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define fori(x, y) for (int i = x; i < y; i++)
#define forj(x, y) for (int j = x; j <= y; j++)

using namespace std;

bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int d = 3; d * d < number; d++)
    {
        if (number % d == 0)
            return false;
    }
    return true;
}

int main()
{
    input;
    int n;
    while (cin >> n && n)
    {
        bool isPrimeNumber = isPrime(n);
        if (isPrimeNumber && n != 11 && n != 23 && n != 29)
        {
            long long r = pow(2, n - 1) * (pow(2, n) - 1);
            cout << "Perfect: " << r << "!" << endl;
        }
        else if (isPrimeNumber)
        {
            cout << "Given number is prime. But, NO perfect number is available." << endl;
        }
        else
        {
            cout << "Given number is NOT prime! NO perfect number is available." << endl;
        }
    }
}