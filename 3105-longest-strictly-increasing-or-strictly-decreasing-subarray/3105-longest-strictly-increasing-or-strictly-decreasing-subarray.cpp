class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int len = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                dec = inc = 1;
            }

            len = max({len, inc, dec});
        }
        return len;
    }
};