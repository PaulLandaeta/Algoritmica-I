#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;  
int number6(int num) {
    int cont = 0;
    while(num>0) {
        if(num%10==6) 
            cont++;
        num/=10;
    }
    return cont;
}
int main() {
    input;
    int cont =0;
    for(int i=0;i<=1    6;i++) {
        cont+=number6(i);
    }
    cout<<cont<<endl;
    return 0;
}