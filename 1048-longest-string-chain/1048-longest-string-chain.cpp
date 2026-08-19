class Solution {
public:
    bool ispredecessor(string & word1, string & word2 ){
        if (word2.size() != word1.size() + 1) return false;
        int i =0;
        int j =0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i]==word2[j]) {
                i++;
            }
            j++;
        }
        return i>=word1.size();
    }
    int f(vector<string>& words, int i , int prev, vector<vector<int>>& dp){
        if(i>=words.size()) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];
        int take = INT_MIN;
        if(prev==0 || ispredecessor(words[prev-1], words[i])){
            take = 1+f(words, i+1, i+1, dp);
        }
        int nottake = f(words, i+1, prev, dp);
        return dp[i][prev] =  max(take, nottake);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(words,0,0,dp);
        vector<int> dp (n,1);
        int maxi = 1;
        for(int i =1;i<n;i++){
            for(int prev_i= 0;prev_i<i;prev_i++){
                if(ispredecessor(words[prev_i], words[i])){
                    dp[i] = max(dp[i], dp[prev_i]+1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};