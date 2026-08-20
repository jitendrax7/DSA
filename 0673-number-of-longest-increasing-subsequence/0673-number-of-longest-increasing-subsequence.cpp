class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp (n,1);
        vector<int> cnt (n,1);
        int maxi = 1;
        for(int i =0;i<n;i++){
            for(int prev_i= 0;prev_i<i;prev_i++){
                if(nums[prev_i]<nums[i]){
                    if(dp[i]<dp[prev_i]+1){
                        cnt[i] = cnt[prev_i];
                        dp[i] = dp[prev_i]+1;
                    }else if(dp[i]==dp[prev_i]+1){
                        cnt[i] += cnt[prev_i];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
     
        int count = 0;
        for(int i =0;i<n;i++){
            if(dp[i]==maxi) count+= cnt[i];
        }

        return count;
    }
};