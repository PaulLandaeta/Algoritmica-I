#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

using namespace std; 

bool solve(string brack)
{
    stack<char> many;
    for (int i = 0; i < brack.size(); i++)
    {
        if (brack[i] == '(' || brack[i] == '[' || brack[i] == '{')
        {
            many.push(brack[i]);
        }
        else
        {
            if ( 
                !many.empty() &&
                ((brack[i] == ')' && many.top() == '(') ||
                (brack[i] == ']' && many.top() == '[') ||
                (brack[i] == '}' && many.top() == '{'))
                )
            {
                many.pop();
            }
        }
    }
    return many.empty();
}

int main()
{
    input;
    int howmany;
    cin >> howmany;
    string concat;
    while (howmany--)
    {
        cin >> concat;
        if (solve(concat))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}