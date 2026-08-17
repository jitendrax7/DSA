class Solution {
public:
    int f(vector<int>& cumsum, int low, int high, vector<vector<int>> & dp){
        if(low==high) return 0;

        if(dp[low][high]!= -1) return dp[low][high];
        int score =0;
        for(int mid =low;mid<high;mid++){
            int leftSum = cumsum[mid]- (low-1>=0?cumsum[low-1]:0);
            int rightSum = cumsum[high]-cumsum[mid];

            if(leftSum<rightSum){
                score = max(score, leftSum + f(cumsum,low, mid, dp));
            }else if(rightSum<leftSum){
                score = max(score,rightSum+f(cumsum,mid+1,high, dp));
            }else{
                score = max({score, leftSum+f(cumsum,low,mid, dp), rightSum+f(cumsum,mid+1,high, dp)});
            }
        }
        return dp[low][high] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> cumsum (n);
        cumsum[0] = stoneValue[0];
        for(int i= 1;i<n;i++){
            cumsum[i]  = cumsum[i-1]+stoneValue[i];
        }

        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(cumsum,0,n-1, dp);
        // vector<vector<int>> dp(n,vector<int>(n,0));

        // for(int low= n-1;low>=0;low--){
        //     for(int high =low+1;high<n;high++){
        //         int score =0;
        //         for(int mid =low;mid<high;mid++){
        //             int leftSum = cumsum[mid]- (low-1>=0?cumsum[low-1]:0);
        //             int rightSum = cumsum[high]-cumsum[mid];
        //             if(leftSum<rightSum){
        //                 score = max(score, leftSum + dp[low][mid]);
        //             }else if(rightSum<leftSum){
        //                 score = max(score,rightSum+dp[mid+1][high]);
        //             }else{
        //                 score = max({score, leftSum+dp[low][mid], rightSum+dp[mid+1][high]});
        //             }
        //         }
        //         dp[low][high] = score;
        //     }
        // }

        // return dp[0][n-1];
    }
};