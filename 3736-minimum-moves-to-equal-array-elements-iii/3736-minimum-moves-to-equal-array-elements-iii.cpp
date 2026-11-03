class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        for (auto n : nums)
            move += maxi - n;

        return move;
    }
};