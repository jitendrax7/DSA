class Solution {
public:
    int f(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>> & dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j] + f(matrix, i-1, j, n,m,dp);
        int upleft = matrix[i][j] + f(matrix, i-1, j-1, n,m,dp);
        int upright = matrix[i][j] + f(matrix, i-1, j+1, n,m,dp);
        return dp[i][j] = min({upleft, up, upright});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp (m,0);
        vector<int> curr(m,0);
        dp = matrix[0];
        for(int i= 1;i<n;i++){
            for(int j = 0;j<m;j++){
                int up = matrix[i][j] + dp[j];
                int upleft = 1e9;
                int upright = 1e9;
                if(j>0) upleft = matrix[i][j] + dp[j-1];
                if(j<m-1)upright =  matrix[i][j] + dp[j+1];
                curr[j] = min({upleft, up, upright});
            }
            dp = curr;
        }

        int mini = INT_MAX;
        for(int j =0;j<m;j++){
            mini = min(mini, dp[j]);
        }
        return mini;
    }
};