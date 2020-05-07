#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX 1000000000
using namespace std; 


// Fuerza Bruta 
long long fibo(long long n){
    if(n == 0 )
        return 0;
    if(n == 1) 
        return 1;
    return fibo(n-1)+fibo(n-2);
}


//DP
long long fiboStore[10000000]; // setear a todos -1

long long fibo(long long n){
    if(fi)
    if(n == 0 )
        return 0;
    if(n == 1) 
        return 1;
    return fibo(n-1)+fibo(n-2);
}

int main () {

}