class Solution {
public:
    vector<vector<int>> t;
    int find(vector<int>& nums, int st, int tar) {
        int j = lower_bound(begin(nums) + st, end(nums), tar) - begin(nums);
        if (j < nums.size() && nums[j] == tar) {
            return j;
        }
        return -1;
    }
    int solve(int i, int inc, vector<int>& nums) {
        if (t[i][inc] != -1)
            return t[i][inc];
        int curr = nums[i] + inc;
        int len = 1;

        int j = find(nums, i + 1, curr + 1);
        if (j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        j = find(nums, i + 1, curr);
        if (j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return t[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        t.assign(n + 1, vector<int>(2, -1));

        int result = 1;
        for (int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }
        return result;
    }
};