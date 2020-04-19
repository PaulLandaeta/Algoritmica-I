#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
// ACCEPTED :)  
using namespace std; 

int main() {
    input;
    int n;
    while(cin>>n && n!=0) {
        map<vector<int>, int> popularCourse;
        int masPopular = 0;
        for(int i=0;i<n;i++) {
            vector<int> frosh(5);
            cin>>frosh[0]>>frosh[1]>>frosh[2]>>frosh[3]>>frosh[4];
            sort(frosh.begin(),frosh.end());
            popularCourse[frosh]++;
            masPopular = max(masPopular,popularCourse[frosh]);
            /* if(popularCourse[frosh] == null) {
                popularCourse[frosh] = 1;
            }else {
                popularCourse[frosh] = popularCourse[frosh] + 1;
            }*/ 
        }
        int result = 0; 
        for (std::map<vector<int>,int>::iterator it=popularCourse.begin(); it!=popularCourse.end(); ++it){
            if(it->second == masPopular) {
                result++;
            }
        }
        cout<<result*masPopular<<endl;
    }
    return 0;
}