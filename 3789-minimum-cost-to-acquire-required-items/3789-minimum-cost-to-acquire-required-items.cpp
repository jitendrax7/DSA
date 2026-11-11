class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        int mini = min(need1, need2);
        long long totalCost = 1LL*mini*min(costBoth,cost1+cost2);
        need1 -= mini;
        need2 -= mini;

        if(need1>0){
            totalCost += 1LL*need1*min(cost1,costBoth);
        }
        if(need2>0){
            totalCost += 1LL*need2* min(cost2,costBoth);
        }

        return totalCost;
    }
};