#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std; 


// Fuerza Bruta 
long long fiboFB(long long n){
    if(n == 0 )
        return 0;
    if(n == 1) 
        return 1;
    return fibo(n-1)+fibo(n-2);
}


//DP
long long fiboStore[10000000]; // setear a todos -1

long long fiboDP(long long n){
    if(fiboStore[n] == - 1) {
        if(n == 0 )
                return 0;
        if(n == 1) 
                return 1;
        fiboStore[n] = fibo(n-1)+fibo(n-2);
    }
    return fiboStore[n];
}

int main () {
    int n;
    cin>>n;
    memset(fiboStore,-1,sizeof(fiboStore));
    cout<<fiboFB(n)<<endl;
    cout<<fiboDP(n)<<endl;
}