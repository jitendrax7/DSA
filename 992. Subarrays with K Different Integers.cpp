# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <string>
# include <map>
# include <unordered_map>
using namespace std;


// 992. Subarrays with K Different Integers
// solve using a sliding window approach, we can find the number of subarrays with at most k distinct integers and subtract the number of subarrays with at most k-1 distinct integers to get the number of subarrays with exactly k distinct integers.

// solution 1 
// using a unordered map to keep track of the count of each integer in the current window

class Solution1 {
public:

    int helper(vector<int>& nums, int goal){
        unordered_map<int,int> m;
        int l = 0;
        int r = 0;
        int count = 0;
        int unique = 0;

        if(goal < 0) return 0;
        while(r < nums.size()){
            m[nums[r]]++;
            while(m.size() > goal && l <= r){
                // unique -= nums[l] &1;
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) -helper(nums, k-1);
    }
};

// solution 2
// using a vector to keep track of the count of each integer in the current window
// this solution is faster than the first one because it uses a vector instead of an unordered map, which has a faster access time

class Solution2 {
public:
    int helper(vector<int>& nums, int goal){
        vector<int> m (nums.size()+1, 0);
        int l = 0;
        int r = 0;
        int count = 0;
        int unique = 0;

        if(goal < 0) return 0;
        while(r < nums.size()){
            if(m[nums[r]] == 0) unique++;
            m[nums[r]]++;
            while(unique > goal && l <= r){
                m[nums[l]]--;
                if(m[nums[l]]==0)unique--;
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) -helper(nums, k-1);
    }
};



int main(){
    Solution1 s1;
    Solution2 s2;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << s1.subarraysWithKDistinct(nums, k) << endl; // 7
    cout << s2.subarraysWithKDistinct(nums, k) << endl; // 7
    return 0;
}