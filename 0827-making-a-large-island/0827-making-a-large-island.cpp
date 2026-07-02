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

            int sizeofU(int u){
                return size[u];
            }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> rd = {0,0,1,-1};
        vector<int> cd = {1,-1,0,0};

        Desjointset ds = Desjointset((n*(n-1))+n-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int r = i+rd[k];
                        int c = j+cd[k];
                        if(r>=n || c>=n || r<0 || c<0 || grid[r][c]==0) continue;
                        int oldid = (n*i)+j;
                        int newid = (n*r)+c;
                        ds.unionbysize(oldid, newid);
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, ds.sizeofU((i*n)+j));
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    for(int k =0;k<4;k++){
                        int r = i+rd[k];
                        int c = j+cd[k];
                        if(r>=n || c>=n || r<0 || c<0 || grid[r][c]==0) continue;
                        st.insert(ds.findUPar((n*r)+c));
                    }

                    int area = 0;
                    for(auto & it:st){
                        area += ds.sizeofU(it);
                    }
                    ans = max(ans,area+1);
                }
            }
        }

        return ans;
    }
};





