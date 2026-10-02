class Solution {
public:
    vector<string> ans;
    void solve(int n, int openCount, string& curr) {
        if (n == 0 && openCount == 0) {
            ans.push_back(curr);
            return;
        }

        if (n > 0) {
            curr.push_back('(');
            solve(n - 1, openCount + 1, curr);
            curr.pop_back();
        }
        if (openCount > 0) {
            curr.push_back(')');
            solve(n, openCount - 1, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, 0, curr);
        return ans;
    }
};