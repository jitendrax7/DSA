class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {


        //approach 1 with sort 
        // sort(arr.begin(), arr.end());

        // arr[0] = 1;
        // int ans = 1;
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]-arr[i-1] >1) arr[i] = arr[i-1]+1;

        //     ans = max(ans,arr[i]);
        // }

        // return ans;


        // no sort 
        int ans = 0;
        int n = arr.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[min(arr[i],n)]++;
        }

        for(int i=1;i<=n;i++){
            if(freq[i]==0) continue;
            ans = min(ans+freq[i], i);
        }

        return ans;
    }
};