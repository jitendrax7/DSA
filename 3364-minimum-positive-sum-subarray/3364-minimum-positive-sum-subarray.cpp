class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int siz = j - i + 1;
                if(siz>r) break;
                if (sum > 0 && siz >= l && siz <= r) {
                    mini = min(mini, sum);
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};