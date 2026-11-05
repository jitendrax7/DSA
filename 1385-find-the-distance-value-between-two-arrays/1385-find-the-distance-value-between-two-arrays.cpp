class Solution {
public:
    bool binarySearch(vector<int>& arr2, int tar, int d) {
        int st = 0;
        int end = arr2.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (abs(arr2[mid] - tar) <= d)
                return false;
            if (arr2[mid] < tar) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return true;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            if (binarySearch(arr2, arr1[i], d))
                count++;
        }
        return count;
    }
};