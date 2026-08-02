class Solution {
public:
    int helper(vector<int> &nums, int i , vector<int> & dp ){
        if(i>=nums.size()) return 1e9;
        if(i==nums.size()-1)return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = 1e9;
        for(int j = 1;j<= nums[i];j++){
            mini = min(mini, helper(nums, i+j,dp)+1);
        }

        return dp[i] =  mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp (n,0);
        
        // for(int i= n-2;i>=0;i--){
        //     int mini = 1e9;
        //     for(int j = 1;j<= nums[i];j++){
        //         if(i+j <n) mini = min(mini, dp[i+j] +1);
        //     }
        //     dp[i] =  mini;
        // }

        // return dp[0];

        int jump = 0;
        int currEnd = 0;
        int farthest  = 0;
        for(int i =0;i<n-1;i++){
            farthest  = max(farthest , i+nums[i]);
            if(i==currEnd){
                jump++;
                currEnd = farthest;
            }
        }

        return jump;
    }
};