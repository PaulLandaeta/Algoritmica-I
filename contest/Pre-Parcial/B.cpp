#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
// ACCEPTED :( 
using namespace std; 

bool solve(string brackets){
    stack<char> bracketStack;
    for(int i=0;i < brackets.size();i++){
        if(brackets[i]=='('||brackets[i]=='['||brackets[i]=='{'){
          bracketStack.push(brackets[i]);
        }else {
          if(!bracketStack.empty() &&
              ((brackets[i]==')' && bracketStack.top()=='(' )||
              (brackets[i]==']' && bracketStack.top()=='[' )||
              (brackets[i]=='}' && bracketStack.top()=='{'))){
                bracketStack.pop();
              }else{
             return false;
            }
          }
    }
    
    return bracketStack.empty();
}
int main(){
    input;
    int ncasos;
    cin>>ncasos;
    while(ncasos--){
        string brackets;
        cin>>brackets;
        if(solve(brackets)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }



    return 0;
}
