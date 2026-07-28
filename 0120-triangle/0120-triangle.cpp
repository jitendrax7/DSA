class Solution {
public:
    // int f(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> & dp ){   // space O(n*n)

    //     if(row==triangle.size()-1) return triangle[row][col];

    //     if(dp[row][col]!=INT_MIN) return dp[row][col];
    //     int down = triangle[row][col] + f(triangle,row+1, col, dp);
    //     int downright = triangle[row][col] + f(triangle,row+1, col+1, dp);

    //     return dp[row][col] = min(down,downright);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {     

        // memo.. + recursion 
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(),INT_MIN));
        // return f(triangle, 0,0, dp);

       // space n , tabulation 
        int n = triangle.size();
        vector<int> dp (n);
        dp = triangle[n-1];
        for(int i =n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j =0;j<triangle[i].size();j++){
                int down = triangle[i][j]+dp[j];
                int downleft = triangle[i][j]+dp[j+1];
                curr[j] = min(down, downleft);
            }
            dp = curr;
        }
        return dp[0];
    }
};