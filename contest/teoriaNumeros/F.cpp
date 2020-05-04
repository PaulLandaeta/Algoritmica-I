#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

//1010101#
//01234567
//binaryNumber.size() = 8
// (a^b)%c
long long modulo(long long a, long long b, long long c)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % c;
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

void solve(string binaryNumber)
{
    if (binaryNumber == "#")
    {
        cout << "NO" << endl;
        return;
    }
    long long result = 0;
    long long powCont = 0;
    long long mod = 131071;
    for (int i = binaryNumber.size() - 2; i >= 0; i--, powCont++)
    {
        if (binaryNumber[i] == '1')
        {
            result += modulo(2, powCont, mod);
            result %= mod;
        }
    }
    // 101
    //cout << result << "result" << endl;
    if (result % mod == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    input;
    string totalNumber = "";
    string number;
    while (cin >> number)
    {
        totalNumber += number;
        if (number[number.size() - 1] == '#')
        {
            solve(totalNumber);
            totalNumber = "";
        }
        
    }
}