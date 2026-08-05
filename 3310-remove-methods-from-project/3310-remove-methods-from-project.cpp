class Solution {
public:
    void dfs(int src,vector<vector<int>>&adj, vector<bool>& vis){
        vis[src] = true;
        for(auto & v:adj[src]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> bugvis(n,false);
        vector<vector<int>> adj(n);
        for(auto & it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        dfs(k,adj,bugvis);
        for(auto & it:invocations){
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i] && !bugvis[i]){
                dfs(i,adj,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]) ans.push_back(i);
        }

        return ans;
    }
};