#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;
int multi(int a,int b) {
    if(a==1) 
        return b;
    else{
        return b+multi(a-1,b);
    }
}

int main()
{
    cout<<multi(5,3)<<endl;
    return 0;
}