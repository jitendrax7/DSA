class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> m(101);
        for(auto i:nums) m[i] = 1;
        int n = k;
        while(n<=100 &&  m[n]){
            n+= k;
        }
        return n;
    }
};