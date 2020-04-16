#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
//#define fori(x,y) for(int i=x; i<=y; i++)
//#define forj(x,y) for(int j=x; j<=y; j++)
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

    for(int i=0;i<26;i++) {
        for(int j=i+1;j<26;j++) {
                for(int k=j+1;k<26;k++){
            string word = chars[i]+chars[j]+chars[k];
            celdas[word]=c;
            c++;
                }
        }
    }

    for(int i=0;i<26;i++) {
        for(int j=i+1;j<26;j++) {
                for(int k=j+1;k<26;k++){
                        for(int l=k+1;l<26;l++){
            string word = chars[i]+chars[j]+chars[k]+chars[l];
            celdas[word]=c;
            c++;
                        }
                }
        }
    }

     for(int i=0;i<26;i++) {
        for(int j=i+1;j<26;j++) {
                for(int k=j+1;k<26;k++){
                        for(int l=k+1;l<26;l++){
                                for(int m=l+1;m<26;m++){
            string word = chars[i]+chars[j]+chars[k]+chars[l]+chars[m];
            celdas[word]=c;
            c++;
                                }
                        }
                }
        }
    }

}
int main()
{
    string word;
    int number = 10;
    // incrementar antes de imprimir 
    cout<<++number<<endl;
    // va imprimir y luego va incrementar
    cout<<number++<<endl;

    // number final 
    cout<<number<<endl;
    return 0;
}