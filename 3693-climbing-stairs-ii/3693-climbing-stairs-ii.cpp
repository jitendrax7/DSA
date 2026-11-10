class Solution {
public:
    // int N;
    // vector<int>t;
    // int f(vector<int>& costs, int i){
        
    //     if(i>=N) return 0;
    //     if(t[i]!=-1) return t[i];
    //     int ans =  costs[i] + 1 +f(costs, i+1);
    
    //     if(i+1<N) ans = min(ans, costs[i+1] +4 +f(costs, i+2));
    //     if(i+2<N) ans = min(ans, costs[i+2] + 9 + f(costs, i+3));
    //     return t[i] =  ans;
    // }
    int climbStairs(int n, vector<int>& costs) {
        // N = n;
        // t.assign(N,-1);
        // return f(costs,0);

        // vector<int>t (N+1,0);

        int first = 0;
        int second = 0;
        int third = 0;
        for(int i = n-1;i>=0;i--){
            int ans =  costs[i] + 1 + first;
            if(i+1<n) ans = min(ans, costs[i+1] +4 + second);
            if(i+2<n) ans = min(ans, costs[i+2] + 9 + third);
            third = second;
            second = first;
            first =  ans;
        }
        return first;
    }
};