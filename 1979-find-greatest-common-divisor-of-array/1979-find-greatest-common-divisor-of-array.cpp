class Solution {
public:
    // int gcd(int a, int b) {
    //     return b == 0 ? a : gcd(b, a % b);
    // }
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto i:nums){
           mn = min(i,mn);
           mx = max(i,mx);
        } 
        return gcd(mn, mx);
    }

};