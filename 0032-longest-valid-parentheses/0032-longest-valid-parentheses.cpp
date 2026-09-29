class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (st.empty() || s[i] == '(' || s[st.top()] == ')') {
                st.push(i);
            } else {
                st.pop();
                int dist = i - (st.empty() ? -1 : st.top());
                maxi = max(maxi, dist);
            }
        }

        return maxi;
    }
};