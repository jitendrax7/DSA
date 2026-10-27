class Solution {
public:
    int M, N;
    bool solve(vector<string>& grid, int i, int j) {
        if (i >= M || j >= N)
            return false;
        if (i == M - 1 && j == N - 1) {
            grid[i][j] = '.';
            return true;
        }
        grid[i][j] = '.';
        if (solve(grid, i, j + 1) || solve(grid, i + 1, j))
            return true;
        grid[i][j] = '#';
        return false;
    }
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        // M = m;
        // N = n;
        // solve(grid, 0, 0);
        for (int i = 0; i < n; i++)
            grid[0][i] = '.';
        for (int i = 0; i < m; i++)
            grid[i][n - 1] = '.';

        return grid;
    }
};