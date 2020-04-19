#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout) 
using namespace std;  

int main() {
   int t; 
   cin>>t; 
   map<string,int> mp;
   for(int i = 0; i < t; i++) {
       string word; 
       cin>>word;
       mp[word]++;
   }
   int queries; 
   cin>>queries;
   for(int i=0; i<queries; i++) {
       cout<<mp[word]<<endl;
   }
}