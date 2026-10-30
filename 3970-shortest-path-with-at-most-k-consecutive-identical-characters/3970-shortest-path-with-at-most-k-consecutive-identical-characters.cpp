class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto & it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> count(n, 0);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        int cnt = 1;

        if (cnt > k)
            return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, count] = pq.top();
            pq.pop();

            if (d > dist[node][count])
                continue;

            if (node == n - 1)
                return d;

            for (auto & it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                int newCount = 1;

                if (labels[node] == labels[adjNode]) {
                    newCount = count + 1;
                }
                if (newCount > k)
                    continue;

                int newDist = d + wt;

                if (newDist < dist[adjNode][newCount]) {
                    dist[adjNode][newCount] = newDist;
                    pq.push({newDist, adjNode, newCount});
                }
            }
        }

        return -1;
    }
};