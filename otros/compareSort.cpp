#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool compare(vector<int> a,vector<int> b) {
    return a.size() > b.size();
}


int main() {
    vector<vector<int> > lista(3); 
    lista[0].push_back(1);
    lista[0].push_back(2);
    lista[0].push_back(3);
    lista[1].push_back(1);
    lista[2].push_back(1);
    lista[2].push_back(2);
    cout<<"=========LISTA NO ORDENADA==========="<<endl;
    for(int i = 0;i<3;i++) {
        cout<<"{"<<i<<"} =>";
        for(int j=0;j<lista[i].size();j++) {
            cout<<"["<<lista[i][j]<<"]";
        }
        cout<<endl;
    }
    
    cout<<"==========Lista ORDENADA==========="<<endl;
    sort(lista.begin(),lista.end(),compare);
    
    for(int i = 0; i < 3; i++) {
        cout<<"{"<<i<<"} =>";
        for(int j=0;j<lista[i].size();j++) {
            cout<<"["<<lista[i][j]<<"]";
        }
        cout<<endl;
    }
    
    
}