class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n =s.size();
        unordered_map<char,int> m;
        int maxi = 0;
        int i = 0;
        for(int j =0;j<n;j++){
            m[s[j]]++;
            while(i<n &&  m[s[j]]>2) m[s[i++]]--;
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};