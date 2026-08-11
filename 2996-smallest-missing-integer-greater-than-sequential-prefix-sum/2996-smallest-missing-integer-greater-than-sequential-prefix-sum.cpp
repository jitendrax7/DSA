class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n =nums.size();
        int prev = nums[0];
        int sum =nums[0];
        unordered_set<int> s(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i]-1==prev){
                sum += nums[i];
                prev = nums[i];
            }else{
                break;
            }
        }

        while(s.count(sum)){
            sum++;
        }
        return sum ;
    }
};