class Solution {
public:
    tuple<bool, int, int> isSortable(vector<int>& nums, int i, int j) {
        int count = 0;
        int mini = nums[j];
        int maxi = nums[j];
        for (int k = i; k < j; k++) {
            if (nums[k] > nums[k + 1]) {
                count++;
            }
            mini = min(mini, nums[k]);
            maxi = max(maxi, nums[k]);
        }
        if (nums[j] > nums[i]) {
            count++;
        }
        return {count <= 1, mini, maxi};
    }
    bool check(vector<int>& nums, int k, int n) {
        int prevMax = -1;
        for (int i = 0; i < n; i += k) {
            auto [subValid, currMin, currMax] = isSortable(nums, i, i + k - 1);
            if (!subValid || prevMax > currMin)
                return false;
            prevMax = currMax;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            if (check(nums, k, n)) {
                sum += k;
            }
        }
        return sum;
    }
};