class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ')'){
                score = st.top() + max(2*score,1);
                st.pop();
            }else{
                st.push(score);
                score = 0;
            }
        }
        return score;
    }
};