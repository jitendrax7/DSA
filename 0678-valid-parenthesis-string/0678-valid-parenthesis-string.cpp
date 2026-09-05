class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for(auto & ch:s){
            if(ch=='('){
                mini++;
                maxi++;
            }else if(ch==')'){
                mini--;
                maxi--;
            }else{
                mini--;
                maxi++;
            }

            if(mini<0) mini =0;
            if(maxi<0) return false;
        }

        return mini==0;
    }
};