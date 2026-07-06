class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        
        int prev = -1;
        int ans = 0;
        for(int i =0;i<intervals.size();i++){

            if(prev!=-1 && ( intervals[i][1]<=intervals[prev][1] )){
                continue;
            }else{
                prev = i;
                ans++;
            }
        }

        return ans;
    }
};