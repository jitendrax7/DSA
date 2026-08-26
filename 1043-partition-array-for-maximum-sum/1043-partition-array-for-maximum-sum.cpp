class Solution {
public:
    int f(vector<int>& arr, int k, int i, vector<int>& dp){
        int n = arr.size();
        if(i==n) return 0;

        if(dp[i]!= -1) return dp[i];

        int maxiAns = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int idx =i;idx< min(i+k, n );idx++){
            len++;
            maxi = max(maxi,arr[idx]);
            int sum =  (len*maxi)+f(arr,k,idx+1,dp);
            maxiAns = max(maxiAns, sum);
        }
        return dp[i] = maxiAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        // return f(arr,k,0,dp);

        for(int i=n-1;i>=0;i--){
            int maxiAns = INT_MIN;
            int maxi = INT_MIN;
            int len = 0;
            for(int idx =i;idx< min(i+k, n);idx++){
                len++;
                maxi = max(maxi,arr[idx]);
                int sum =  (len*maxi)+dp[idx+1];
                maxiAns = max(maxiAns, sum);
            }
            dp[i] = maxiAns;
        }
        return dp[0];
    }
};