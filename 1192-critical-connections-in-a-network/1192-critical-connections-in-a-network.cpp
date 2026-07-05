class Solution {
public:
    int times = 1;
    
    void dfs(vector<vector<int>> & adj , int src, int parent, vector<bool> & vis,vector<int> & tin,vector<int> & low, vector<vector<int>> & ans ){

        vis[src] = true;
        tin[src] = low[src] = times;
        times++;
        for(int v :adj[src]){
            if(v==parent) continue;

            if(vis[v]){
                low[src] = min(low[src], low[v]);
            }else{
                dfs(adj, v,src, vis, tin,low,ans);

                low[src] = min(low[src], low[v]);

                if(low[v]>tin[src]){
                    ans.push_back({src,v});
                }
            }    
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto & it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> tin (n);
        vector<int> low (n);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        dfs(adj , 0,-1 ,vis,tin,low,ans);
        return ans;

    }
};