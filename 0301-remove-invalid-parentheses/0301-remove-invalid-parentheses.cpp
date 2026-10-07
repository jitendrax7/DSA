class Solution {
public:
    int mini = 0;
    unordered_set<string> st;

    void solve(string & s,int i,int count,  string & curr){
        if(count<0) return;
        if ((int)curr.size() + (int)(s.size() - i) < mini) return;
        if(i==s.size()){
            if(count==0){
                if(mini<curr.size()){
                    st.clear();
                    mini = curr.size();
                    st.insert(curr);
                }
                else if(mini==curr.size()){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i]!='(' && s[i]!=')'){         // take char 
            curr.push_back(s[i]);
            solve(s,i+1,count, curr);
            curr.pop_back();
            return;
        }

        if(s[i]=='('){      // take  '('
            curr.push_back('(');
            solve(s, i+1,count+1 , curr);
            curr.pop_back();
        }else if( s[i]==')' && count>0 ){     // take ')' only count > 0 
            curr.push_back(')');
            solve(s,i+1,count-1, curr);
            curr.pop_back();
        }

        solve(s,i+1,count,curr);     // not take 
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        solve(s,0,0,curr);
        vector<string> ans;
        for(auto & it:st){
            ans.push_back(it);
        }
        return ans;
    }
};