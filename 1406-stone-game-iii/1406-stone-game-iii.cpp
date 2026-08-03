class Solution {
public:
    int f(vector<int>& stoneValue , int i, int n , vector<int> & dp ){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        // int result = INT_MIN;
        int result = stoneValue[i] - f(stoneValue, i+1,n, dp);
        if(i+1<n) result = max(result, stoneValue[i]+ stoneValue[i+1] - f(stoneValue, i+2,n, dp));
        if(i+2<n) result = max(result, stoneValue[i]+ stoneValue[i+1]+ stoneValue[i+2] - f(stoneValue, i+3,n,dp));
        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n =stoneValue.size();
        // vector<int> dp(n+3,0);
        int next_1 = 0,  next_2 = 0, next_3 = 0;
        // int diff  = f(stoneValue, 0, n, dp);
        for(int i=n-1;i>=0;i--){
            int result = stoneValue[i] - next_1;
            if(i+1<n) result = max(result, stoneValue[i]+ stoneValue[i+1] - next_2);
            if(i+2<n) result = max(result, stoneValue[i]+ stoneValue[i+1]+ stoneValue[i+2] - next_3);
            next_3 = next_2;
            next_2 = next_1;
            next_1 = result;
        }
        if(next_1>0) return "Alice";
        else if(next_1<0) return  "Bob";
        return "Tie";
    }
};  