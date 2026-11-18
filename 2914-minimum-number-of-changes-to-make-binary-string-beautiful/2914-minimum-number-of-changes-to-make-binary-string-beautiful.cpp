class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int change = 0;
        for(int i = 0;i<n;i+=2){
            change += !(s[i]==s[i+1]);
        }

        return change;
    }
};