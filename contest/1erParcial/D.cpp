#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;

int main()
{
    input; 
    stack<int> pila1;
    stack<int> pila2;
    stack<int> pila3;
    int n1, n2, n3; 
    cin>>n1>>n2>>n3;
    int cont1=0, cont2=0, cont3=0; 
    int val; 
   // cin>>val;
    for(int i=0; i<n1; i++){
        cin>>val;
        pila1.push(val); 
        cont1+=val;
    }
    for(int i=0; i<n2; i++){
        cin>>val;
        pila2.push(val); 
        cont2+=val;
    }
    for(int i=0; i<n3; i++){
        cin>>val;
        pila3.push(val); 
        cont3+=val;
    }
    while (!((cont1==cont2) && (cont2==cont3) && (cont1==cont3))){
        if(cont1>=cont2 && cont1>=cont3){
            cout<<"aca"<<cont1<<endl;
            cont1-=pila1.top();
            pila1.pop();
        }else if(cont2 >=cont1 && cont2>=cont3){
            cout<<"aca2"<<endl;
            cont2-=pila2.top();
            pila2.pop();
        } else{
            cout<<"aca3"<<endl;
            cont3-=pila3.top();
            pila3.pop();
        } 
    }
    cout<<cont1<<endl;
}