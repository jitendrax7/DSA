class Solution {
public:

     // recursion + memoization 
    
    // int f(vector<vector<int>>& grid, int i, int j1 , int j2, int n, int m, vector<vector<vector<int>>> & dp){
    //     if(j1<0 || j1>=m || j2<0 || j2>= m) return -1e9;
    //     if(i==n-1){
    //         if(j1==j2) return grid[i][j1];
    //         else return grid[i][j1]+grid[i][j2];
    //     }
    //     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    //     int maxi = INT_MIN;
    //     int curr = j1==j2?grid[i][j1]:grid[i][j1] + grid[i][j2];
    //     for(int dj1=-1;dj1<= +1; dj1++){
    //         for(int dj2=-1;dj2<= +1; dj2++){
    //             int sum = curr + f(grid, i+1, j1+dj1, j2+dj2, n, m ,dp);

    //             maxi = max(maxi, sum);
    //         }
    //     }

    //     return dp[i][j1][j2] =  maxi;
    // }


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp (m,vector<int>(m,0));
        vector<vector<int>> curr (m,vector<int>(m,0));
        
        for(int j1 =0;j1<m;j1++){
            for(int j2 =0;j2<m;j2++){
                if(j1==j2) dp[j1][j2] =  grid[n-1][j1];
                else dp[j1][j2] =  grid[n-1][j1]+grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi = -1e9;
                    int cur = j1==j2?grid[i][j1]:grid[i][j1] + grid[i][j2];
                    for(int dj1=-1;dj1<= +1; dj1++){
                        for(int dj2=-1;dj2<= +1; dj2++){
                            int newj1  = j1+dj1;
                            int newj2 = j2+dj2;
                            if(newj1>=0 && newj1<m && newj2>=0 && newj2<m ) maxi = max(cur + dp[j1+dj1][j2+dj2], maxi);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            dp = curr;
        }

        return dp[0][m-1];
    }
};