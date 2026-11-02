class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int moves = 0;
        for (auto i : nums) {
            moves += abs(i - median);
        }
        return moves;
    }
};