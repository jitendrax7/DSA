class Solution {
public:
    int f(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int idx=i;idx<=j;idx++){
            int cost = nums[i-1]*nums[idx]*nums[j+1] + f(nums,i,idx-1,dp) + f(nums,idx+1,j,dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        // vector<vector<int>> dp(n-1,vector<int>(n-1,-1));
        // return f(nums, 1,n-2,dp);
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxi = INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int cost = nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1] + dp[idx+1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];

    }
};