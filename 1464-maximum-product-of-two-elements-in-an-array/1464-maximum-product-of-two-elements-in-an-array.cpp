class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0;
        int second = 0;
        for(int & n:nums){
            if(first<n){
                second = first;
                first = n;
            }else if(second<n)  second = n;
            
        }
        return (first-1)*(second-1);
    }
};