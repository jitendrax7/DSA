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

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto & stone:stones){
            maxrow = max(maxrow,stone[0]);
            maxcol = max(maxcol,stone[1]);
        }
        Desjointset ds = Desjointset(maxrow+maxcol+1);
        unordered_set<int> stonesNode;
        for(auto & stone:stones){
            int row = stone[0];
            int col = stone[1]+maxrow+1;
            ds.unionbysize(row,col);
            stonesNode.insert(row);
            stonesNode.insert(col);
        }

        int component = 0;
        for(auto & it:stonesNode){
            if(ds.findUPar(it)==it) component++;
        }

        return stones.size()-component;
    }
};