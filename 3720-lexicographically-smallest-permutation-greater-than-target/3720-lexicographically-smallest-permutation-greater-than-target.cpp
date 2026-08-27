class Solution {
public:
   
    string ans = "";
    bool solve(vector<int> &count,string & target ,int i,string & curr, bool isgreater ) {
        if(i==target.size()){
            if(isgreater){
                ans = curr;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']==0) continue;
            if(!isgreater&& ch<target[i]) continue;

            curr.push_back(ch);
            count[ch-'a']--;
            int greater = isgreater || ch>target[i];
            if(solve(count,target, i+1,curr,greater)) return true;
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);
        for(auto &ch:s) count[ch-'a']++;
        string curr = "";
        solve(count,target,0,curr,false);
        return ans;
    }
};