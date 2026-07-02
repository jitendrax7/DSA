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

        int sizeofU(int u){             // modify in dsu add a method to get a size of u
            return size[u];
        }
};

class Solution {
private:
    bool isValid(int row, int col , int n){
        return row>=0 && col>=0 && row<n && col <n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> rd = {0,0,1,-1};
        vector<int> cd = {1,-1,0,0};

        Desjointset ds(n*n);

        // step 1   - connect all the adj nodes 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int r = i+rd[k];
                    int c = j+cd[k];
                    if(isValid(r,c,n) && grid[r][c]==1){
                        int nodeNo = (n*i)+j;
                        int adjnodeNo = (n*r)+c;
                        ds.unionbysize(nodeNo, adjnodeNo);
                    }
                }
            }
        }

        int ans = 0;

        // step 1 -- travel all zeros and get the max of there adj if ones , simple means convert thats zero to ones and then connect all there adj ones island and find the maximam 

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                ans = max(ans, ds.sizeofU((i*n)+j));
                if(grid[i][j]==1) continue;
                unordered_set<int> st;

                for(int k =0;k<4;k++){    // go to all adj and get the unique ultimate parent
                    int r = i+rd[k];
                    int c = j+cd[k];
                    if(isValid(r,c,n) && grid[r][c]==1){
                        st.insert(ds.findUPar((n*r)+c));
                    }
                }

                int totalsize = 0;
                for(auto & it:st){   // sum  the size of all ultimate parent
                    totalsize += ds.sizeofU(it);
                }
                ans = max(ans,totalsize+1);
            }
        }

        return ans;
    }
};





