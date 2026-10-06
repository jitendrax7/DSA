class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int st = 0;
        int count = 0;
        for(auto c :s){
            if(c=='('){
                // st.push(c);
                st++;
            }else{
                if(st==0){
                    count++;
                }else{
                    // st.pop();
                    st--;
                }
            }
        }
        return st+count;
    }
};