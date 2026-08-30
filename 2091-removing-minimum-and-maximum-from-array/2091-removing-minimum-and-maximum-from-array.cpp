class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
        int minidx =0;
        int maxidx =0;
        for(int i =0;i<n;i++){
            if(nums[i]<nums[minidx]) minidx = i;
            if(nums[maxidx]<nums[i]) maxidx = i;
        }

        return min({
            (max(minidx,maxidx)+1),
            (n-min(minidx,maxidx)),
            ((minidx+1)+(n-maxidx)),
            ((n-minidx)+(maxidx+1))
        });
    }
};