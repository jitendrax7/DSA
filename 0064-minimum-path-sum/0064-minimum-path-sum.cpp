class Solution {
public:
    // int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return 1e9;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int left = grid[i][j]+f(grid, i,j-1, dp);
    //     int up = grid[i][j]+f(grid, i-1,j, dp);

    //     return dp[i][j] = min(left, up);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return f(grid,n-1,m-1,dp);


    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,0);
        dp[0] = grid[0][0];
        for(int i = 0;i<n;i++){
            vector<int> curr(m,0);
            for(int j =0;j<m;j++){
                if(j==0 && i==0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up += dp[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j>0) left += curr[j-1];
                    else left += 1e9;
                    curr[j] = min(left,up);
                }
            }
            dp = curr;
        }
        return dp[m-1];
    }
};