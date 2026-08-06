class DSU{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,0);
        for(int i =0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    void unionbysize(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent) return;

        if(size[x_parent] > size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }else{
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
};


class Solution {
public:  
    bool solve(vector<vector<int>>& adj, int src, int destination, vector<bool> &vis ){
        if(src==destination) return true;
        vis[src] = true;
        for(auto & v:adj[src]){
            if(!vis[v] &&  solve(adj,v,destination,vis)) return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // vector<vector<int>> adj (n);
        // for(auto & it:edges){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        // vector<bool> vis (n, false);
        // return solve(adj, source, destination, vis);

        DSU ds(n);
        for(auto & it:edges){
            ds.unionbysize(it[0],it[1]);
        }

        return ds.find(source)==ds.find(destination);
    }
};