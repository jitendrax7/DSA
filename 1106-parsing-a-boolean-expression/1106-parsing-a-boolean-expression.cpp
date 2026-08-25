class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();

        stack<char> st;
        for(int i =0;i<n;i++){
            if(expression[i]==',') continue;
            if(expression[i]!=')') {
                st.push(expression[i]);
                continue;
            }

            bool hasFalse = false;
            bool hasTrue = false;
            while(st.top()!='('){
                char t = st.top();
                st.pop();
                if(t=='t') hasTrue = true;
                else if(t=='f') hasFalse = true;
            }
            st.pop();
            char ex = st.top();
            st.pop();

            bool res;
            if(ex=='!') res = hasFalse;
            else if(ex=='&') res = !hasFalse;
            else if(ex=='|') res = hasTrue;

            st.push(res?'t':'f');
        }
        
        return st.top()=='t'?1:0;
    }
};