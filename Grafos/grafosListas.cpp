#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int main() 
{ 
    input; 
    int nodos,aristas; 
    cin>>nodos>>aristas;
    vector<int> grafo[nodos];
    
    for(int i=0;i<aristas;i++) {
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }

    for(int i=0;i<nodos;i++) {
        cout<<"{"<<(i+1)<<"}=>";
        for(int j=0;j<grafo[i].size();j++) {
            cout<<"["<<grafo[i][j]+1<<"]";
        }
        cout<<endl;
    }
    return 0; 
} 