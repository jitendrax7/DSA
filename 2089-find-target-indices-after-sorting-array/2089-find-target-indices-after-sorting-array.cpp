class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int countless = 0;
        for (int n : nums) {
            if (n == target) {
                count++;
            } else if (n < target) {
                countless++;
            }
        }

        vector<int> ans;
        for (int i = countless; i < countless + count; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};