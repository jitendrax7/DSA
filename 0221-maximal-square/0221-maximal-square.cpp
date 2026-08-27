class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0' || i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] =
                        min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};