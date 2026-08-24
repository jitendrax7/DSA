class Solution {
public:
    int n ;
    int f(vector<int>& PS, int idx , vector<int>& dp){
        if(idx==n-1) return PS[n-1];
        if(dp[idx]!=-1) return dp[idx];
        int take = PS[idx] - f(PS,idx+1,dp);
        int skip = f(PS,idx+1,dp);

        return dp[idx] = max(take, skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> PS (n);
        PS[0] = stones[0];
        for(int i=1;i<n;i++) PS[i] = PS[i-1]+stones[i];
        
        // return f(PS,1, dp);
        // vector<int> dp(n,0);
        int dp_next = PS[n-1];

        // dp[n-1] = PS[n-1];

        for(int i =n-2;i>=1;i--){
            int take = PS[i] - dp_next;
            int skip = dp_next;
            dp_next = max(take, skip);
        }
        return dp_next;
    }
};