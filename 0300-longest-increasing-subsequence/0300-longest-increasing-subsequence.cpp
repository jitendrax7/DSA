class Solution {
public:
    int f(vector<int>& nums, int i, int lasti, vector<vector<int>> & dp){
        if(i==nums.size()) {
            return 0;
        }
        if(dp[i][lasti+1]!=-1) return dp[i][lasti+1];
        int take = INT_MIN;
        if(lasti==-1 ||  nums[i]>nums[lasti]){
            take = 1+f(nums,i+1,i,dp);
        }
        int nottake = f(nums,i+1,lasti,dp);

        return dp[i][lasti+1] =  max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp memoazation
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(nums,0,-1,dp);

        // tabulation way 
        // vector<int> dp (n,1);
        // int maxi = 1;
        // for(int i =1;i<n;i++){
        //     for(int prev_i= 0;prev_i<i;prev_i++){
        //         if(nums[prev_i]<nums[i]){
        //             dp[i] = max(dp[i], dp[prev_i]+1);
        //         }
        //     }
        //     maxi = max(maxi, dp[i]);
        // }
        // return maxi;

        vector<int> temp ;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int idx = lower_bound(temp.begin(),temp.end(), nums[i])- temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};