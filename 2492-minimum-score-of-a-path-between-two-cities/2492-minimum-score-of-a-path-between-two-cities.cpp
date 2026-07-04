//  // apporoch 1 - simple start from 1 and apply a dfs or bfs and before check its visited or not check the edge weight min(ans,w) here only dfs code you can do a bfs as well 
//  // time complecity = O(V+E)

// class Solution {
// public:
//     void dfs(vector<vector<pair<int,int>>>& adj ,int src,  int & score, vector<bool> & vis){
//         vis[src] = true;
//         for(auto & [v,w]:adj[src]){
//             score = min(score, w);
//             if(!vis[v]){
//                 score = min(score, w);
//                 dfs(adj, v,score,vis);
//             }
//         }
//     }
//     int minScore(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int,int>>> adj(n+1);
//         for(auto edge:roads){
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];
//             adj[u].push_back({v,w});
//             adj[v].push_back({u,w});
//         }

//         vector<bool> vis(n+1, false);

//         int ans = INT_MAX;
//         dfs(adj, 1,ans, vis);
//         return ans;
//     }
// };


// apporoch 2 - use of dsu its give a optimal approach , here use a desjointset and fist union all vertex and then travell all the edge and check its a part or vertex starting (1) or not check its untimate parent with the help of dsu if yes then chek its minmum to ans or not min(ans,w) 
//time complecity - 
class Desjointset {
    vector<int> perent, size;
    public:
        Desjointset(int n){
            size.resize(n+1,1);
            perent.resize(n+1);
            for(int i=0;i<=n;i++){
                perent[i] = i;
            }
        }

        int findUPar(int u){
            if(u==perent[u]) return u;
            return perent[u] = findUPar(perent[u]);
        }
        void unionbysize(int u, int v){
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if(up_u==up_v) return;

            if(size[up_u]<size[up_v]){
                perent[up_u] = up_v;
                size[up_v] += size[up_u];
            }else{
                perent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        Desjointset ds(n);

        for(auto & edge:roads){
            ds.unionbysize(edge[0],edge[1]);
        }
  
        int ans = INT_MAX;
        int p1 = ds.findUPar(1);
        for(auto & edge:roads){
            if(edge[2]<ans && p1==ds.findUPar(edge[1]) ){
                ans = edge[2];
            }
        }

        return ans;

    }
};
