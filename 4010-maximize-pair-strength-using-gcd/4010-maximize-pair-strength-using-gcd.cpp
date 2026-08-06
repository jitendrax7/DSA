class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n =nums.size();
        long long ans = 0;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                long long m = 1ll*nums[i]*nums[j];
                long long c = gcd(nums[i],nums[j]);
                ans = max(ans, m/(c*c));
            }
        }

        return ans;
    }
};