class Solution {
public:
    int reverseDegree(string s) {
        int rDegree = 0;
        for(int i = 0;i<s.size();i++){
            int revp = 26-(s[i]-'a');
            rDegree += revp*(i+1);
        }

        return rDegree;
    }
};