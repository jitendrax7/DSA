class Solution {
public:
    const int MOD = 1e9+7;
    int helper(vector<int> & nums, int idx, int gcd1 , int gcd2, vector<vector<vector<int>>> & dp){
        if(idx==nums.size()){
            bool isavalble = (gcd1!=0) && (gcd2!= 0);
            bool isgcdequal = (gcd1==gcd2);
            return (isavalble && isgcdequal)?1:0;
        }

        if(dp[idx][gcd1][gcd2]!=-1){
            return dp[idx][gcd1][gcd2];
        }

        int skip = helper(nums, idx+1, gcd1, gcd2, dp);
        int pair1 = helper(nums, idx+1, __gcd(gcd1,nums[idx]), gcd2, dp);
        int pair2 = helper(nums, idx+1, gcd1, __gcd(gcd2,nums[idx]), dp);

        return dp[idx][gcd1][gcd2] =  (1LL*skip+pair1+pair2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<vector<int>>>  dp(nums.size()+1, vector<vector<int>>(201, vector<int>(201,-1)));
        return helper(nums,0,0,0, dp);
    }
};