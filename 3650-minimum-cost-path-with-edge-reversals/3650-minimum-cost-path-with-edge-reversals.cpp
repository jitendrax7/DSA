class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto & it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w*2});
        }

        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            auto [dis,u] = q.top();
            q.pop();
            if (dis > dist[u]) continue;
            
            for(auto [v,w]:adj[u]){
                if(dis+w<dist[v]){
                    q.push({dis+w,v});
                    dist[v] = dis+w;
                }
            }
        }

        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};