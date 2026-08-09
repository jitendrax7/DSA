class Solution {
public:
    int n ;
    int dp[2][101][101];
    int f(vector<int>& piles, int isAlice, int i, int m){
        if(i>=n) return 0;

        if(dp[isAlice][i][m] != -1) return dp[isAlice][i][m];
        int result = isAlice==1?-1:INT_MAX;
        int stones = 0;
        for(int x =1;x<= min(2*m,n-i);x++){
            stones += piles[i+x-1];
            if(isAlice){
                result = max(result,stones+f(piles,0,i+x,max(m,x)));
            }else{
                result = min(result, f(piles,1,i+x,max(m,x)));
            }
        }

        return dp[isAlice][i][m] =  result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1, sizeof(dp));
        return f(piles,1,0,1);
    }
};