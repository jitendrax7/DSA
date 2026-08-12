class Solution {
public:
    int f(string & word1, string & word2, int i, int j,vector<vector<int>> & dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] !=-1) return dp[i][j];
        if(word1[i]==word2[j]) return f(word1,word2,i-1,j-1 ,dp);
        return dp[i][j] =  min({
            f(word1,word2,i-1,j,dp),  // insert
            f(word1,word2,i,j-1,dp),  // delete
            f(word1,word2,i-1,j-1,dp)  // replace
        })+1;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>dp (m+1,0);
        vector<int>curr (m+1,0);
        // return f(word1,word2,n-1,m-1,dp);

        // for(int i=0;i<=n;i++) dp[i][0] = i;

        for(int j=0;j<=m;j++) dp[j] = j;
        for(int i= 1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){

                if(word1[i-1]==word2[j-1]) curr[j] = dp[j-1];
                else curr[j] =  min({
                    dp[j],  // insert
                    curr[j-1],  // delete
                    dp[j-1]  // replace
                })+1;
            }
            dp = curr;
        }

        return dp[m];
    }
};