#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 
int main(){
    //input;
    int n,m;
    while(cin>>n>>m) {
        int p,k,v;
            vector<int> graph[1000001]; /// el juez acepta pero la maquina no 
            for(int i = 0 ;i < n; i++) {
                int node;
                cin>>node;
                graph[node].push_back(i+1);
            }
            while(m--) {// 6 5 4 3 2 1 0
                cin>>k>>v;
                if(graph[v].size()>=k){
                    cout<<graph[v][k-1]<<endl;
                }
                else {
                    cout<<0<<endl;
                }
            }

    }
    
}