class Solution {
public:
    int f(string & text1, string & text2, int idx1 , int idx2, vector<vector<int>> &dp){
        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!= -1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) return 1+f(text1, text2, idx1-1, idx2-1, dp);

        return dp[idx1][idx2] = max(f(text1, text2, idx1-1, idx2,dp), f(text1, text2, idx1, idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int  n = text1.size();
        int  m = text2.size();
        // return f(text1, text2, n-1,m-1,dp);
        vector<int> dp (m+1,0);
        vector<int> curr (m+1,0);

        // for(int i =0;i<=m;i++) dp[i] = 0;
        // curr[0] = 0;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){ 
                if(text1[i-1]==text2[j-1]) curr[j] =  1+ dp[j-1] ;
                else curr[j] = max(dp[j], curr[j-1]);
            }
            dp = curr;
        }
        return dp[m];
    }
};