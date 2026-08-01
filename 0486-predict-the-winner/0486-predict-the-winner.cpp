class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> & dp){
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i = nums[i] + min(solve(nums,i+2,j, dp), solve(nums,i+1,j-1,dp));
        int take_j = nums[j] + min(solve(nums,i,j-2,dp), solve(nums,i+1,j-1 ,dp));

        return dp[i][j] = max(take_i ,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int & i:nums) totalsum += i;
        vector<vector<int>> dp (n, vector<int>(n,-1));
        int player1 = solve(nums,0,n-1, dp);
        int player2 = totalsum - player1;
        return player1>=player2;
    }
};