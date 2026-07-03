class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<bool>> vis (n,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            int t = pq.top().first;
            auto [i,j] = pq.top().second;
            pq.pop();
            if(i==n-1 && j==n-1) return t;
            int rd[] = {0,0,1,-1};
            int cd[] = {-1,1,0,0};
            for(int a=0;a<4;a++){
                int r = rd[a]+i;
                int c = cd[a]+j;
                if(r>=n || c>=n || r<0 || c<0 || vis[r][c]) continue;
                int nt = max(t,grid[r][c]);
                pq.push({nt,{r,c}});
                vis[r][c] = true;
            }
        }

        return 0;
    }
};