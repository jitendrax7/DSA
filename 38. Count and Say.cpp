# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <string>
# include <map>
using namespace std;

string helper(string s){
        string ans = "";
        int n = s.size();
        int count = 1;

        for(int i=1;i<=n;i++){
            if(i<n && s[i]==s[i-1]){
                count ++;
                continue;
            }
            ans += to_string(count)+ string(1, s[i-1]);
            count = 1;
        }
        return ans;
}

    string countAndSay(int n) {
        string ans= "1";
        for(int i=0;i<n-1;i++){
            ans = helper(ans);
        }
        return ans;
    }

int main(){
    int n = 2;
    cout<<countAndSay(n);
    return 0;
}    