class Solution {
public:
    int f(vector<int>& prices, int i, int buy, vector<vector<int>> & dp){   // memoazation
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit =  max(-prices[i]+ f(prices,i+1, 0, dp),f(prices, i+1,1,dp));
        }else{
            profit =   max(prices[i]+f(prices,i+2,1,dp), f(prices, i+1,0,dp));
        }

        return dp[i][buy] =  profit;  
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));   // for recursion
        // return f(prices,0,1, dp);

        // vector<vector<int>> dp(n+2,vector<int>(2,0));  // for tabulation
        // vector<int> dp_one (2,0);  // for tabulation  space optim
        // vector<int> dp_two (2,0);  // for tabulation space optim
        // vector<int> curr (2,0);  // for tabulation
        int buy1 = 0 ,not_buy1 = 0;  // now with variable more optimize space
        int buy2 =0;

        for(int i=n-1;i>=0;i--){
            int curr_buy = max(-prices[i]+not_buy1 ,buy1);
            int curr_not_buy = max(prices[i]+buy2, not_buy1);
            buy2 = buy1;
            buy1 = curr_buy;
            not_buy1 = curr_not_buy;
        }

        return buy1;
    }
};