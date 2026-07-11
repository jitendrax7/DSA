class DisjointSet {
    public:
    vector<int> size, parent, edges;

    DisjointSet(int n){
        size.resize(n,1);
        edges.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int u){
        if(u==parent[u]) return u;

        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v){
        int p_u = findUPar(u);
        int p_v = findUPar(v);
        if(p_u==p_v) {
            edges[p_u]++;
            return;
        }
        if(size[p_u]<size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
            edges[p_v] += edges[p_u]+1;
        }else{
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
            edges[p_u] += edges[p_v]+1;
        }
    }
    
};


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        DisjointSet ds(n);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            ds.unionBySize(u,v);
        }
        // unordered_map<int,int> m;
        // for(int i=0;i<n;i++){
        //     m[ds.findUPar(i)]++;
        // }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(i==ds.findUPar(i)){
                int nodeCount = ds.size[i];
                int edgeCount = ds.edges[i];
                if(nodeCount*(nodeCount-1)/2 == edgeCount) ans++;
            }
        }
        return ans;
    }
};