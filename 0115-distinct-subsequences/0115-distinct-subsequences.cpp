class Solution {
public:
    // int f(string s, string t, int i, int j , vector<vector<int>>& dp ){
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int nottake = f(s,t,i+1,j,dp);
    //     int take =0;
    //     if(s[i]==t[j]){
    //         take = f(s,t,i+1,j+1,dp);
    //     }
    //     return dp[i][j] = take+nottake;
    // }
    int numDistinct(string s, string t) {
        int n =s.size();
        int m =t.size();

        // recursion + memoazation
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(s,t,0,0,dp);

        // tabulation
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++) dp[i][m] = 1;

        // memory optimization
        vector<int> dp(m+1,0);
        vector<int> curr(m+1,0);
        dp[m] =1;
        curr[m] = 1;
        for(int i =n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int nottake = dp[j];
                int take =0;
                if(s[i]==t[j]){
                    take = dp[j+1];
                }
                curr[j] = 1LL*take+nottake;
            }
            dp = curr;
        }

        return dp[0];
    }
};