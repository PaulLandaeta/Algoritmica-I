#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

/*
    T = algxalgxalgxalgxalgxalgo
    P = algo
*/

// O(n) = T.size()* (P.size()-1)
// O(n) = T.size()*P.size() // 1000000
bool compareIngenuo(string T, string P)
{

    for (int i = 0; i < T.length(); i++) // T.size()
    {
        int j = 0;
        int k = i;
        while (k < T.length() && j < P.length() && T[k] == P[j]) // P.size()-1
        {
            k++;
            j++;
        }

        if (j == P.length())
        {
            return true;
        }
    }
    return false;
}
// P = qwertyuiop
// P = -1000000000
// P = yyyyyyyyy
// P = abccabccabc

// O(n) = P.size()* C = P.size()
vector<int> kmp_procces(string P)
{
    vector<int> patron(P.size());
    int i = 0, j = -1;
    patron[0] = -1;
    while (i < P.size())
    {
        while (j >= 0 && P[i] != P[j])
        {
            j = patron[j];
        }
        i++;
        j++;
        patron[i] = j;
    }
    return patron;
}


int kmp(string T, string P)
{
    int i = 0, j = 0,cont=0;             // 3
    vector<int> patron = kmp_procces(P); // P.size()

    // O(n) = T.size();
    while (i < T.length())              // T.size()
    {
        while (j >= 0 && T[i] != P[j])
        {
            j = patron[j];
        }
        i++;
        j++;
        if (j == P.length())
        {
            cont++;
            j = patron[j]; // verificar si otro P dentro T 
        }
    }
    return cont;                         // 1  
}

// O(n) = 3+P.size()+T.size()+1 = P.size()+T.size()

// O(n) = P.size() + T.size() = n+m 

int main()
{
    input;
    string T, P;
    getline(cin,T);
    getline(cin, P);
    cout<<kmp(T,P)<<endl;

    /*
    vector<int> patron = kmp_procces(P);
    for (int i = 0; i < patron.size(); i++)
    {
        cout << "[" << patron[i] << "]";
    }
    */
    return 0;
}