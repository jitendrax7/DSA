class Solution {
public:
    vector<string> ans;
    void solve(int n, int openCount, string curr) {
        if (n == 0 && openCount == 0) {
            ans.push_back(curr);
            return;
        }

        if (n > 0) {
            solve(n - 1, openCount + 1, curr+'(');
        }
        if (openCount > 0) {
            solve(n, openCount - 1, curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, "");
        return ans;
    }
};