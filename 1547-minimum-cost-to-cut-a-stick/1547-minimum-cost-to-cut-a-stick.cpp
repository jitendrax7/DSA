class Solution {
public:
    int f(vector<int>& cuts,int i, int j ,vector<vector<int>> & dp ){  
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int idx=i+1;idx<j;idx++){
            int cost = (cuts[j]-cuts[i])+f(cuts,i,idx,dp) + f(cuts,idx,j,dp);
            mini = min(mini,cost);
        }

        return dp[i][j] = mini==INT_MAX?0:mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        // vector<vector<int>> dp(m,vector<int>(m,-1));
        // return f(cuts, 0,m-1,dp);
        vector<vector<int>> dp(m,vector<int>(m,0));

        for(int i= m-1;i>=0;i--){
            for(int j= i+1;j<m;j++){
                int mini = INT_MAX;
                for(int idx=i+1;idx<j;idx++){
                    int cost = (cuts[j]-cuts[i])+dp[i][idx] + dp[idx][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini==INT_MAX?0:mini;
            }
        }
        
        return dp[0][m-1];

    }
};