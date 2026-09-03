class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minodd = INT_MAX;
        for(auto i:nums1) if(i&1) minodd = min(minodd,i);

        auto helper = [&](int t){
            for(auto i:nums1){
                if((i&1)!=t && i<=minodd) return false;
            }
            return true;
        };
        return helper(1) || helper(0);
    }
};