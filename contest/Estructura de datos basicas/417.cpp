#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

map<string,int> celdas;
void generador() {
    int c = 1;
    vector<string> chars(27);
    for(int i=0;i<26;i++) {
        chars[i] = "";
        chars[i] += (char)(i+'a');
    }
    // a b c d 
    for(int i=0;i<26;i++) {
        string word="";
        word+=chars[i];
        celdas[word]=c;
        c++;
    }
    // ab ac ad 
    for(int i=0;i<26;i++) {
        for(int j=i+1;j<26;j++) 
        {
            string word = chars[i]+chars[j];
            celdas[word]=c;
            c++;
        }
    }

}
int main() 
{ 
    input; 
    string word;

    
    generador();
    while(cin>>word){
        cout<<celdas[word]<<endl;
    }
    return 0; 
} 