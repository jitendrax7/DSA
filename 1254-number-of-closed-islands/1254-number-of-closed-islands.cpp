class Solution {
public:
    class DSU {
        vector<int> parent, size;

    public:
        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v)
                return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU ds(n * m);
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nr = dr[k] + i;
                    int nc = dc[k] + j;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 0) {
                        int u = i * m + j;
                        int v = nr * m + nc;
                        ds.unionBySize(u, v);
                    }
                }
            }
        }

        set<int> allComponent;
        set<int> boundryComponent;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0)
                    continue;
                int node = ds.findUPar(i * m + j);

                allComponent.insert(node);
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    boundryComponent.insert(node);
                }
            }
        }

        return allComponent.size() - boundryComponent.size();
    }
};