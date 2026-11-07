class Solution {
public:
    struct Busy {
        int time;
        int server;
        int idx;
    };
    struct Compare {
        bool operator()(Busy& a, Busy& b) { return a.time > b.time; }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>Avl;
        priority_queue<Busy, vector<Busy>, Compare> Navl;

        for (int i = 0; i < n; i++) {
            Avl.push({servers[i], i});
        }

        vector<int> ans(m);
        long long t = 0;
        for (int i = 0; i < m; i++) {

            t = max(t, (long long)i);

            if (Avl.empty()) {
                t = max(t, (long long)Navl.top().time);
            }
            while (!Navl.empty() && Navl.top().time <= t) {
                Avl.push({Navl.top().server, Navl.top().idx});
                Navl.pop();
            }

            auto [server, idx] = Avl.top();
            Avl.pop();
            ans[i] = idx;
            Navl.push({(int)(t + tasks[i]), server, idx});
        }

        return ans;
    }
};