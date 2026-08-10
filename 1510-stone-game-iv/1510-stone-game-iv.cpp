class Solution {
public:
    bool f(int n, vector<int> & dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int m=1;m*m<=n;m++){
            if(!f(n-m*m,dp)) return dp[n] = true;
        }

        return dp[n] =  false;
    }
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        // return f(n, dp);
        for(int i =1;i<=n;i++){
            for(int m=1;m*m<=i;m++){
                if(!dp[i-m*m]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};