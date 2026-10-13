class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> temp ;
        for(int & i :nums){
            temp.push_back(1LL*i*i);
        }
        sort(temp.begin(),temp.end());
        long long ans = 0;
        int k = n/2;
        for(int i = 0;i<k;i++){
            ans -= temp[i];
        }
        for(int i = k;i<n;i++){
            ans += temp[i];
        }

        return ans;
    }
};