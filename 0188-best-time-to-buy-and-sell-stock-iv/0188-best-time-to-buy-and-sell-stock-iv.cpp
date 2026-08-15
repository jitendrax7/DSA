class Solution {
public:
    int f(vector<int>& prices,int k, int i,int t, vector<vector<int>>& dp){
        if(t>=k*2) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int profit = 0;
        if(t%2==0){
            profit = max( -prices[i]+f(prices,k, i+1,t+1,dp), f(prices,k, i+1,t,dp));
        }else{
            profit = max( prices[i]+f(prices,k, i+1,t+1,dp), f(prices,k, i+1,t,dp));
        }

        return dp[i][t] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // k =k1;
        // vector<vector<int>> dp(n,vector<int>(k*2,-1));
        vector<int> dp (k*2+1,0);
        vector<int> curr (k*2+1,0);
        // return f(prices,k, 0,0,dp);
        
        for(int i = n-1;i>=0;i--){
            for(int t =0;t<k*2;t++){
                if(t%2==0) curr[t] = max( -prices[i]+ dp[t+1] , dp[t]);
                else curr[t] = max( prices[i]+dp[t+1], dp[t]);
            }
            dp = curr;
        }
        return dp[0];
    }
};