class Solution {
public:
    struct Info {
        int count = 0;
        bool special = true;
        int lastDiff = -1;
        int lastIdx = -1;
    };
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,Info> mp;

        for(int i = 0;i<nums.size();i++){
            auto& x = mp[nums[i]];

            if (x.count == 0) {
                x.count = 1;
                x.lastIdx = i;
            }
            else if (x.count == 1) {
                x.lastDiff = i - x.lastIdx;
                x.lastIdx = i;
                x.count = 2;
            }
            else {
                int diff = i - x.lastIdx;

                if (diff != x.lastDiff)
                    x.special = false;

                x.lastDiff = diff;
                x.lastIdx = i;
                ++x.count;
            }
        }

        int count =0;
        for(auto & it:mp){
            if(it.second.count==3 && it.second.special) count++;
        }

        return count;
    }
};