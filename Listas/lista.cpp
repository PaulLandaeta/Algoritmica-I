#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

void mostrarDatos(list<string> &sList)
{
    list<string>::iterator pos;
    pos = sList.begin();
    while (pos != sList.end())
    {
        cout << *pos << endl;
        pos++;
    }
}

int main()
{
    //input;
    list<string> listaNombres;
    listaNombres.push_back("Paul");
    listaNombres.push_back("Pedro");
    listaNombres.push_back("Pablo");
    listaNombres.push_back("Alicia");
    listaNombres.push_back("Alejandra");
    cout << listaNombres.size() << endl;
    listaNombres.pop_back();
    cout << listaNombres.size() << endl;
    //Crear iterador
    list<string>::iterator posList;
    posList = listaNombres.begin();
    cout << *posList << endl;
    *posList = "Juan";
    cout << *posList << endl;
    cout<<"==============Mostrar Lista=============="<<endl;
    mostrarDatos(listaNombres);
    cout<<"==============Ordenar Lista=============="<<endl;
    listaNombres.sort();
    mostrarDatos(listaNombres);
    return 0;
}