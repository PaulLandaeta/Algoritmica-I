#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
vector<int>  graph[1000];
int main() {
    input;
    int nodes; 
    cin>>nodes; 
    int edges; 
    cin>>edges;
    map<string,int> mapaCiudades;
    map<int,string> mapaKeyCiudad; 
    int nodesCont = 1; 
    for(int i = 0; i< edges; i++) {
        string cityOne, cityTwo;
        cin>>cityOne>>cityTwo;
        if(!mapaCiudades[cityOne]) {
            mapaCiudades[cityOne] = nodesCont;
            mapaKeyCiudad[nodesCont] = cityOne;
            nodesCont++;
        }
        if(!mapaCiudades[cityTwo]) {
            mapaCiudades[cityTwo] = nodesCont;
            mapaKeyCiudad[nodesCont] = cityTwo;
            nodesCont++;
        }
        graph[].push_back();

    }
}