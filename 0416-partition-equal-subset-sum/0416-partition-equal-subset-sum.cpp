class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> dp (sum+1,false);
        vector<bool> curr (sum+1,false);

        if(arr[0]<=sum) dp[arr[0]] = true;
        dp[0] = true;

        for(int i= 1;i<n;i++){
            curr[0] = true;
            for(int target = 1;target<=sum;target++){
                bool nottake = dp[target];
                bool take = false;
                if(arr[i]<=target){
                    take = dp[target-arr[i]];
                }
                
                curr[target] =  nottake || take;
            }
            
            dp = curr;
        }
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto & i:nums) sum += i;
        if(sum&1) return false;
        return isSubsetSum(nums,sum/2);
    }
};