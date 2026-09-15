class Solution {
public:

    // int n;
    // bool isPalindrome(string & s, int i , int j){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // vector<vector<bool>> isPalindrome;
    // int solve(string & s, int k, int i, int j, vector<vector<int>> &t){
    //     if(i>=n || j>=n )
    //         return 0;

    //     if(t[i][j]!=-1) return t[i][j];    
    //     if(isPalindrome[i][j]){
    //         int take = 1+solve(s,k,j+1, j+k, t);
    //         int grow = solve(s,k,i,j+1, t);
    //         int slide = solve(s,k,i+1, j+1, t);
    //         return t[i][j]=  max({take, grow, slide});
    //     }
    //     int grow = solve(s,k,i,j+1,t);
    //     int slide = solve(s,k,i+1, j+1,t);

    //     return t[i][j] = max(grow, slide);
    // }
    int maxPalindromes(string & s, int k) {
        int n = s.size();
        if(k==1) return n;
        vector<vector<bool>> isPalindrome (n, vector<bool>(n,false));

        for(int L =1;L<=n;L++){
            for(int i = 0;i+L<=n;i++){
                int j = i+L-1;
                if(i==j){
                    isPalindrome[i][j] = true;
                }else if(i+1==j){
                    isPalindrome[i][j] = s[i]==s[j];
                }else{
                    isPalindrome[i][j] = (s[i]==s[j] && isPalindrome[i+1][j-1]);
                }
            }
        }
        vector<vector<int>> t (n+1, vector<int> (n+1, 0));
        // return solve(s,k,0,k-1, t); 

        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(isPalindrome[i][j]){
                    int take = 1 + (j+k<=n ? t[j+1][j+k] :0);
                    int grow = t[i][j+1];
                    int slide = t[i+1][j+1];
                    t[i][j]=  max({take, grow, slide});
                    continue;
                }
                int grow = t[i][j+1];
                int slide = t[i+1][j+1];

                t[i][j] = max(grow, slide);
            }
        }

        return t[0][k-1];
    }
};