class Solution {
public:
    int f(vector<int>& nums,int i, int sum){
        if(i==0){
            if(nums[i]==0 && sum==0) return 2;
            if(sum==0 || sum==nums[i]) return 1;
            return 0;
        }
        int notTake = f(nums, i-1, sum);
        int take = 0;
        if(nums[i]<=sum) take = f(nums, i-1, sum-nums[i]);
        return take+notTake;
    }
    int findways(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        // return f(nums, n-1, target);
        if(nums[0]==0)  dp[0][0] = 2;
        else dp[0][0] = 1;
        if (nums[0]!=0 && nums[0] <= target) dp[0][nums[0]] = 1;
        for(int i =1;i<n;i++){
            for(int tar =0;tar<=target;tar++){
                int notTake = dp[i-1][tar];
                int take = 0;
                if(nums[i]<=tar) take = dp[i-1][tar-nums[i]];
                dp[i][tar] =  take+notTake;
            }
        }
        return dp[n-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(auto & it:nums) totalSum += it;
        if(totalSum-target<0 || (totalSum-target)%2) return false;
        return findways(nums, (totalSum-target)/2);
    }
};