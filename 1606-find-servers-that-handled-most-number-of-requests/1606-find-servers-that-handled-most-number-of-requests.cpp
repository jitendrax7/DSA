class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> avalable;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busyServer;

        vector<int> reqCount(k,0);

        for (int i = 0; i < k; i++)
            avalable.insert(i);

        int maxi = 0;
        for (int i = 0; i < n; i++) {

            int arrTime = arrival[i];
            int l = load[i];
            while (!busyServer.empty() && busyServer.top().first <= arrTime) {
                auto [_, idx] = busyServer.top();
                busyServer.pop();
                avalable.insert(idx);
            }

            if (avalable.empty())
                continue;

            auto it = avalable.lower_bound(i % k);

            if (it == avalable.end()) {
                it = avalable.begin();
            }

            int id = *it;
            busyServer.push({arrTime + l, id});
            avalable.erase(id);
            reqCount[id]++;
            maxi = max(maxi, reqCount[id]);
        }

        vector<int> busiestServer;
        for (int id = 0;id<k;id++) {
            if (reqCount[id] == maxi) {
                busiestServer.push_back(id);
            }
        }

        return busiestServer;
    }
};