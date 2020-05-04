#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
long long x, y, d;
void extendedEuclid(long long a, long long b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    ////
    long long x1 = y;
    long long y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main()
{
    input;
    int t;
    cin >> t;
    while (t--)
    {
        long long x, k;
        cin >> x >> k;

        long long a = x / k;
        long long b = (x + k - 1) / k;
        extendedEuclid(a, b);
        cout << a << " " << b << endl;
        cout << x << " " << y << " " << d << endl;
    }
}

// 5 = 2x + 3y
// 5 = 3x + 2y
// 1 = 
// 1 = 2(5) + 3