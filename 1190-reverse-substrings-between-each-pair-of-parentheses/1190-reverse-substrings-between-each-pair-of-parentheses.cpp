class Solution {
public:
    // string reverseParentheses(string s) {
    //     string t;
    //     for (auto& c : s) {
    //         if (c != ')') {
    //             t.push_back(c);
    //             continue;
    //         }

    //         string temp = "";
    //         while (t.back() != '(') {
    //             temp.push_back(t.back());
    //             t.pop_back();
    //         }
    //         t.pop_back();
    //         t += temp;
    //     }
    //     return t;
    // }
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";
        for (auto& c : s) {
            if (c == '(') {
                st.push(curr);
                curr = "";
            } else if (c == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            } else
                curr += c;
        }
        return curr;
    }
};
