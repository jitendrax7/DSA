class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = logs.size();
        auto lambda = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };
        sort(begin(logs), end(logs), lambda);
        int q = queries.size();
        vector<pair<int, int>> timeIdx(q);
        for (int i = 0; i < q; i++) {
            timeIdx[i] = {queries[i], i};
        }

        sort(begin(timeIdx), end(timeIdx));

        vector<int> res(q);

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        for (auto& [time, idx] : timeIdx) {
            // Range
            int st = time - x;
            int end = time;

            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            while (i < m && logs[i][1] < st) {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0)
                    mp.erase(logs[i][0]);
                i++;
            }

            res[idx] = n - mp.size();
        }

        return res;
    }
};