class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;
        int n =nums.size();
        int allZero = 1;
        for(auto &x :nums){
            if(x!=0) allZero =0;
            totalXOR ^= x;
        }
        if(totalXOR>0) return n;
        return allZero?0:n-1;
    }
};