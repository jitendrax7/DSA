class Solution {
public:
    // int f(string word1, string word2, int i, int j,vector<vector<int>> &dp){
    //     if(i==0 && j==0) return word1[i]==word2[j]?0:2;
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;

    //     if(dp[i][j]!= -1) return dp[i][j];
    //     if(word1[i]==word2[j]) return f(word1,word2,i-1,j-1,dp);
        
    //     return dp[i][j]=  min(f(word1,word2,i-1,j,dp),f(word1,word2,i,j-1,dp))+1;
        
    // }
    int longestCommonSubsequence(string & text1, string & text2) {
        int  n = text1.size();
        int  m = text2.size();
        vector<int> dp (m+1,0);
        vector<int> curr (m+1,0);

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){ 
                if(text1[i-1]==text2[j-1]) curr[j] =  1+ dp[j-1] ;
                else curr[j] = max(dp[j], curr[j-1]);
            }
            dp = curr;
        }
        return dp[m];
    }
    int minDistance(string word1, string word2) {
        int n =word1.size();
        int m =word2.size();
        int lcs = longestCommonSubsequence(word1,word2);
        return n+m-(2*lcs);
    }

};