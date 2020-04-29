#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int gcd(int a, int b)
{
    // condicion ternaria
    return (b == 0) ? a : gcd(b, a % b);
}
/* condicion ternaria
if(b==0){
  return  a
}
else {
 return  gcd(b,a%b)
}
*/
int main()
{
    input;
    int cases;
    cin >> cases;
    cin.ignore();
    while (cases--)
    {
       
        string numbers;
        getline(cin, numbers);
        istringstream isNumber(numbers);
        int i = 0;
        vector<int> numberList(110);
        while (isNumber >> numberList[i])
        {
            i++;
        }


        int maxGCD = 0;
        for (int j = 0; j < i; j++)
        {
            for (int k = j + 1; k < i; k++)
            {
                maxGCD = max(maxGCD, gcd(numberList[j], numberList[k]));
            }
        }

        cout << maxGCD << endl;
    }
}