class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int result = INT_MAX;
        int i = 0;
        int j = 0;
        int currSum = 0;
        int bestmin = INT_MAX;
        vector<int> minLenTillI (n, INT_MAX);
        while(j<n){
            currSum += arr[j];
            while(i<j && currSum>target){
                currSum -= arr[i++];
            }

            if(currSum==target){
                int len = j-i+1;
                if(i>0 && minLenTillI[i-1] != INT_MAX){
                    result = min(result, len + minLenTillI[i-1]);
                }
                bestmin = min(bestmin, len);
            }
            minLenTillI[j] = bestmin;
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};