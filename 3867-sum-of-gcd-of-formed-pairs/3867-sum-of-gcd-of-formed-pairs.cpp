class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        
        // vector<int> prefixGcd(n);  // its not good practice to manupulate the source data , I did it because I wanted the runtime to be fast
        
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            nums[i] = gcd(mx, nums[i]);
        }

        sort(nums.begin(),nums.end());
        long long sum = 0;
        for(int i =0;i<n/2;i++){
            sum += gcd(nums[i],nums[n-1-i]);
        }

        return sum;
    }
};