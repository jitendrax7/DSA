class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move = 0;
        int mini = *min_element(nums.begin(),nums.end());
        for(auto n:nums){
            move += n-mini;
        }
        return move;
    }
};