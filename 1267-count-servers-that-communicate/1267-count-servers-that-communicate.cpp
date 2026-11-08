class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_set<int> st;
        int n = grid.size();
        int m  = grid[0].size();
        for(int i = 0;i<n;i++){
            int prev = -1;
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    int id = m*i+j;
                    if(prev!=-1){
                        st.insert(id);
                        st.insert(prev);
                    }
                    prev = id;
                }
            }
        }
        for(int j = 0;j<m;j++){
            int prev = -1;
            for(int i = 0;i<n;i++){
                if(grid[i][j]==1){
                    int id = m*i+j;
                    if(prev!=-1){
                        st.insert(id);
                        st.insert(prev);
                    }
                    prev = id;
                }
            }
        }

        return st.size();
    }
};