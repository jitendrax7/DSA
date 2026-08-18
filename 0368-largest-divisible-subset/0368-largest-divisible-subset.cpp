class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int maxi = 1;
        int lastidx = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i] %nums[j]==0 && dp[i]<dp[j]+1 ) {
                    prev[i] = j;
                    dp[i] = dp[j]+1;
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int> ans;
        while(lastidx!=-1){
            ans.push_back(nums[lastidx]);
            lastidx = prev[lastidx];
        }
        return ans;
    }
};