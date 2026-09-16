class Solution {
public:
    const int M = 1e9+7;
    // int t[1001][1001];
    // int solve(int n, int k, int i){
    //     if(k==0) return 1;
    //     if(i>=n) return 0;
    //     if(t[k][i] != -1) return t[k][i];
    //     long long take =0 ;
    //     for(int j =i+1;j<n;j++){
    //         take = (take + solve(n, k-1,j) ) % M;
    //     }
    //     long long skip = solve(n,k,i+1) % M;

    //     return t[k][i] =  take + skip;
    // }
    int numberOfSets(int n, int K) {
        // memset(t,0 , sizeof(t));
        // return solve(n,k,0) % M;
        vector<vector<int>> t (K+1, vector<int>(n+1, 0));
        for(int i =0;i<n;i++){
            t[0][i] = 1;
        }

        for(int k = 1;k<=K;k++){
            vector<int> preRowSum (n+1, 0);
            for(int x = n-1;x>=0;x--){
                preRowSum[x] = ( preRowSum[x+1] + t[k-1][x] ) % M;
            }
            for(int i = n-1;i>=0;i--){
                long long take = preRowSum[i+1];
                long long skip = t[k][i+1] % M;

                t[k][i] =  (take + skip)% M;
            }
        }

        return t[K][0];
    }
};