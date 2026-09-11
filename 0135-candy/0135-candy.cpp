class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = 1;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]) {
                i++;
                candy++;
                continue;
            }

            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                i++;
                peak++;
                candy += peak;
            }

            int valley = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                i++;
                candy += valley;
                valley++;
            }

            if(peak<valley){
                candy += (valley-peak);
            }
        }

        return candy;
    }
};