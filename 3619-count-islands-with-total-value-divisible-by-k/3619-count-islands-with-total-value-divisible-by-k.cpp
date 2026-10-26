class Solution {
public:
    int n, m, K;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if (grid[i][j] <= 0)
            return 0;
        int curr = grid[i][j];
        grid[i][j] = 0;
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);

        return (up + down + left + right + curr) % K;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && dfs(grid, i, j) % k == 0)
                    count++;
            }
        }

        return count;
    }
};