class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
     
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m,false));
        deque<pair<int,pair<int,int>>> dq;
        dq.push_back({0,{0,0}});
        vis[0][0] = true;
        while(!dq.empty()){
            int d = dq.front().first;
            auto [row, col] = dq.front().second;
            dq.pop_front();

            if(row==n-1 && col==m-1) return d;
            int rd[] = {0,0,1,-1};
            int cd[] = {-1,1,0,0};
            for(int i=0;i<4;i++){
                int newr = rd[i]+row;
                int newc = cd[i]+col;
                if(newr>=n || newc>=m || newr<0 || newc<0 || vis[newr][newc]) continue; 

                if(grid[newr][newc]==1){
                    dq.push_back({d+1,{newr,newc}});
                }else{
                    dq.push_front({d,{newr,newc}});
                }

                vis[newr][newc] = true;
            }
        }

        return 0;
    }
};