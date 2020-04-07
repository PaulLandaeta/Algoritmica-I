#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() 
{ 
    input; 
    int nodos,aristas; 
    cin>>nodos>>aristas;
    int ma[nodos][nodos];
    for(int i=0;i<nodos;i++) {
        for(int j=0;j<nodos;j++) {
            ma[i][j]=0;
        }
    }
    for(int i=0;i<aristas;i++) {
        int a,b;
        cin>>a>>b;
        ma[a-1][b-1]=1;
        ma[b-1][a-1]=1;
    }

    for(int i=0;i<nodos;i++) {
        for(int j=0;j<nodos;j++) {
            cout<<"["<<ma[i][j]<<"]";
        }
        cout<<endl;
    }
    return 0; 
} 