class Solution {
public:
    int f(vector<int> & nums, int idx , vector<int>& dp ){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!= -1) return dp[idx];
        int skip = f(nums, idx+1 , dp);
        int robb = f(nums, idx+2 ,dp)+nums[idx];

        return dp[idx] = max(skip,robb);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums, 0 ,dp);
    }
};