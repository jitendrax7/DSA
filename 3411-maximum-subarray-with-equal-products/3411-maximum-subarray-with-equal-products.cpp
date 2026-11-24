class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            long long pro = 1;
            long long gc_d = 0;
            long long lc_m = 1;

            for (int j = i; j < n; j++) {
                if (nums[j] != 0 && pro > LLONG_MAX / nums[j]) {
                    break;
                }

                pro *= nums[j];

                gc_d = gcd(gc_d, (long long)nums[j]);
                lc_m = lcm(lc_m, (long long)nums[j]);

                if (pro == lc_m * gc_d) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};