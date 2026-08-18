class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int zerocount = 0;
        for(auto & x:nums){
            m[x]++;
        }

        if(k==1 || n==k){
            int ans = -1;
            for(auto & i:nums){
                if(m[i]==1 || n==k){
                    ans = max(ans,i);
                }
            }
            return ans;
        }

        if(m[nums[n-1]]>1 && m[nums[0]]>1) return -1;
        else if(m[nums[n-1]]>1) return nums[0];
        else if(m[nums[0]]>1) return nums[n-1]; 

        return max(nums[0], nums[n-1]);
    }
};