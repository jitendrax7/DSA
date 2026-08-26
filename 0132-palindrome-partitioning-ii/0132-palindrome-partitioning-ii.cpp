class Solution {
public:
    
    bool isPalindrome(string &s, int i, int j){
        int n = s.size();
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string &s, int i, int n, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        // left substrig is pali.
        for (int idx = i; idx < n; idx++) {
            if (isPalindrome(s, i, idx)) {
                int partitions = 1 + f(s, idx + 1, n, dp);
                mini = min(mini, partitions);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string& s) {
        int n = s.size();
        // vector<int> dp (n+1,-1);
        // return f(s,0,n,dp)-1;
        vector<int> dp (n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
            for (int idx = i; idx < n; idx++) {
                if (isPalindrome(s, i, idx)) {
                    int partitions = 1 + dp[idx+1];
                    mini = min(mini, partitions);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};