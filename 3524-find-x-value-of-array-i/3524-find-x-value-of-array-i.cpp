class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long > result(k,0);
        vector<long long > prevCount(k,0);

        for(int i =0;i<n;i++){
            vector<long long> currCount(k,0);
            int currElementRem = nums[i]%k;
            currCount[currElementRem]++;
            for(int x =0;x<k;x++){
                int newrem = (1ll*x*nums[i]%k)%k;
                currCount[newrem] += prevCount[x];
            }
            prevCount = currCount;

            for(int x = 0;x<k;x++){
                result[x] += currCount[x];
            }
        }
        return result;
    }
};