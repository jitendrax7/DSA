class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto & it:nums){
            mini =  min(mini,it);
            maxi =  max(maxi,it);
            s.insert(it);
        }

        vector<int> ans;
        for(int i=mini+1;i<maxi;i++){
            if(!s.count(i)) ans.push_back(i);
        }

        return ans;
    }

};