class Solution {
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() <n-1) return -1;

        Desjointset st = Desjointset(n);
        for(auto & edge:connections){
            int u =edge[0];
            int v =edge[1];
            st.unionbysize(u,v);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(st.findUPar(i)==i) ans++;
        }

        return ans-1;

    }
};