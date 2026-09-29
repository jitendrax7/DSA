class Solution {
public:
    int n, m;
    int t[101][101][201];
    bool isValid(vector<vector<char>>& grid, int i, int j, int count) {
        if (i >= n || j >= m)
            return false;
        count += grid[i][j] == '(' ? 1 : -1;
        if (count < 0)
            return false;
        if (t[i][j][count] != -1)
            return t[i][j][count];
        if (i == n - 1 && j == m - 1)
            return t[i][j][count] = count == 0;

        return t[i][j][count] = isValid(grid, i + 1, j, count) ||
                                isValid(grid, i, j + 1, count);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        memset(t, -1, sizeof(t));
        return isValid(grid, 0, 0, 0);
    }
};