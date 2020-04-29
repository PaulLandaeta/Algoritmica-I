#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool isPrime(int number)
{
    int cont = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
        return true;
    return false;
}

bool isPrime2(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int d = 3; d*d < number; d++)
    {
        if (number % d == 0)
            return false;
    }
    return true;
}

int main()
{

    int number = 1234379;
    //number = 234567215;
    cout << (isPrime2(number) ? "Es número primo" : "No es primo") << endl;
}