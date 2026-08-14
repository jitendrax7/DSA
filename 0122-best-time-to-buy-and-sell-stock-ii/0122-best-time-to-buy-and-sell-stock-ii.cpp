class Solution {
public:
    int f(vector<int>& prices,int i, int buy, vector<vector<int>> & dp){
        if(i==prices.size()) return 0;
        int profit = 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            profit = max( (-prices[i]+f(prices,i+1,0 ,dp)), f(prices,i+1,1,dp));
        }else{
            profit = max(prices[i]+f(prices,i+1,1,dp), f(prices,i+1,0,dp));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int buy = 0;  
        int notbuy = 0;
        for(int i=n-1;i>=0;i--){
            int currbuy  = max( (-prices[i]+notbuy), buy);
            int currnotbuy = max(prices[i]+buy, notbuy);
            buy = currbuy;
            notbuy = currnotbuy;
        }
        return buy;
    }
};