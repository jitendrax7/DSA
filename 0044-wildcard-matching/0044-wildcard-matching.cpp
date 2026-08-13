class Solution {
public:
    bool f(string & s, string & p, int i, int j, vector<vector<int>> & dp){
        if(j==0 && i==0) return true;
        if(j==0 && i>0) return false;
        if(i==0){
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j] =   f(s,p,i-1,j-1,dp);
        }
        else if(p[j-1]=='*') return dp[i][j] = f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp) ;

        return dp[i][j] = false;
    }
    bool isMatch(string & s, string & p) {
        int n = s.size();
        int m = p.size();
        vector<bool>dp (m+1,false);
        vector<bool>curr (m+1,false);
        dp[0] = true;
        for(int j=1;j<=m;j++){
            int fl = 1;
            for(int i=1;i<=j;i++){
                if(p[i-1]!='*'){
                    fl = 0;
                    break;
                }
            }
            dp[j] = fl;
        }

        for(int i =1;i<=n;i++){
            fill(curr.begin(), curr.end(), false);
            for(int j =1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = dp[j-1];
                }
                else if(p[j-1]=='*')  curr[j] = dp[j] || curr[j-1];
            }
            dp = curr;
        }
        return dp[m];
    }
};