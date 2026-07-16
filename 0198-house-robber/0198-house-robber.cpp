
// //  Memoazation technuque
// class Solution {
// public:
//     int f(vector<int> & nums, int idx , vector<int>& dp ){
//         if(idx>=nums.size()) return 0;
//         if(dp[idx]!= -1) return dp[idx];
//         int skip = f(nums, idx+1 , dp);
//         int robb = f(nums, idx+2 ,dp)+nums[idx];

//         return dp[idx] = max(skip,robb);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return f(nums, 0 ,dp);
//     }
// };


// // tabulation techneque;
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0], nums[1]);
//         vector<int> dp(n,-1);
//         dp[0] = nums[0];
//         dp[1] = max(nums[1], nums[0]);

//         for(int i =2;i<n;i++){
//             dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
//         }
//         return dp[n-1]
//     }
// };

// tabulation techneque with space optimize;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        // vector<int> dp(n,-1);
        int prev1 = nums[0];
        int prev2 = max(nums[1], nums[0]);
        int res = prev2;
        for(int i =2;i<n;i++){
            res = max(nums[i]+prev1, prev2);
            prev1 = prev2;
            prev2 = res;
        }
        return res;
    }
};