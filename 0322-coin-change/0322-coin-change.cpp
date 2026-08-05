class Solution {
public:
    int f(vector<int>& coins,int i, int amount ,vector<vector<int>> & dp){
        if(i==0) {
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[i][amount] !=-1) return dp[i][amount];
        int take = 1e9;
        if(coins[i]<=amount) take =  1+f(coins, i, amount-coins[i], dp);
        int nottake = f(coins, i-1 , amount,dp);

        return dp[i][amount] =  min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp (amount+1,0);
        vector<int>curr (amount+1,0);
        // int coin = f(coins, n-1,amount, dp);
        // return coin>=1e9?-1:coin;

        for(int a =0;a<=amount;a++){
            if(a % coins[0]==0) dp[a] = a/coins[0];
            else dp[a] =  1e9;
        }

        for(int i =1;i<n;i++){
            for(int a =0;a<=amount;a++){
                int take = 1e9;
                if(coins[i]<=a) take =  1 + curr[a-coins[i]];
                int nottake = dp[a];
                curr[a] =  min(take,nottake);
            }
            dp = curr;
        }

        return dp[amount]>=1e9?-1:dp[amount];
    }
};