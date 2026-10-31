class Solution {
public:
    int n, m;
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int i, int j, bool isright){
        if(i>=n || j>= m) return 0;

        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j][isright]!=-1) return dp[i][j][isright];

        if(grid[i][j]==1){
            return dp[i][j][isright] =  isright?solve(grid,i+1,j,0):solve(grid,i,j+1,1);
        }

        return dp[i][j][isright] = (solve(grid,i+1,j,0) + solve(grid,i,j+1,1)) % MOD;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<vector<int>> (m,vector<int>(2,-1)));
        return solve(grid,0,0,0);


    }
};