class Solution {
public:
    // int fee;
    // int f(vector<int>& prices, int i, int buy, vector<vector<int>> & dp){
    //     if(i>=prices.size()) return 0;
    //     int profit = 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy){
    //         profit =  max(-prices[i]-fee+f(prices,i+1,0 ,dp) , f(prices,i+1,1,dp));
    //     }else{
    //         profit = max(prices[i]+f(prices,i+1,1,dp), f(prices,i+1,0,dp));
    //     }

    //     return dp[i][buy] =  profit;
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // fee = fe;
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(prices,0,1,dp);
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        int buy =0;
        int not_buy =0;
        for(int i=n-1;i>=0;i--){
            int curr_buy = max(-prices[i]-fee+not_buy , buy);
            int curr_not_buy = max(prices[i]+buy , not_buy);
            buy = curr_buy;
            not_buy = curr_not_buy;
        }
        return buy;
    }
};