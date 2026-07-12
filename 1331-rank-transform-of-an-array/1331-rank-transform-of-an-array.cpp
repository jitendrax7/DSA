class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<pair<int,int>> temp ;
        for(int i = 0;i<n;i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(),temp.end());
        vector<int> res (n);
        res[temp[0].second] = 1;
        for(int i=1;i<n;i++){   
            if(temp[i].first== temp[i-1].first) res[temp[i].second] = res[temp[i-1].second];
            else res[temp[i].second] = res[temp[i-1].second]+1;
        }

        return res;
    }
};