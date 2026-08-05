class Solution {
public:
    int f(vector<int>& coins, int sum, int i , vector<vector<int>> & dp){
        if(i==0) {
            if(sum % coins[0]==0) return 1;
            else return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nottake = f(coins, sum,i-1,dp);
        int take = 0;
        if(coins[i]<=sum) take = f(coins,sum-coins[i],i, dp);

        return dp[i][sum] =  take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long> dp(amount+1, 0);
        vector<long> curr (amount+1, 0);
        // return f(coins, amount,n-1, dp);

        for(int sum = 0;sum<=amount;sum++){
            if(sum % coins[0]==0) dp[sum] = 1;
        }

        for(int i =1;i<n;i++){
            for(int sum=0;sum<=amount;sum++){
                int nottake = dp[sum];
                int take = 0;
                if(coins[i]<=sum) take = curr[sum-coins[i]];
                curr[sum] =  1ll*take + nottake;
            }
            dp = curr;
        }

        return dp[amount];
    }
};