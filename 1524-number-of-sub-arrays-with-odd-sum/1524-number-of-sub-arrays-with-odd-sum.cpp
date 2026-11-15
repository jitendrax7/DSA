class Solution {
public:
    int M = 1e9 +7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count  = 0;
        int even = 1;
        int odd = 0;
        int preSum = 0;
        for(int i = 0;i<n;i++){
            preSum += arr[i];
            if(preSum & 1){
                count = (count + even) % M;
                odd++;
            }else{
                count = (count + odd) % M;
                even++;
            }
        }

        return count;
    }
};