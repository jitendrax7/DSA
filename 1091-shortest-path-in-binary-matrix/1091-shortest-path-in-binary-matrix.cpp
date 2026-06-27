class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>> q;

        q.push({0,0});
        dist[0][0] = 1;
        
        vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
        while(!q.empty()){
            int oldrow = q.front().first;
            int oldcol = q.front().second;
            q.pop();
            for(auto dir:direction){
                int newrow = oldrow+dir.first;
                int newcol = oldcol+dir.second;
                if(newrow<0 || newcol<0 || newrow>=n || newcol>=n || grid[newrow][newcol]==1) continue;

                if(dist[newrow][newcol]!= -1) continue;
                dist[newrow][newcol] = dist[oldrow][oldcol]+1;
                q.push({newrow,newcol});
            }
        }

        return dist[n-1][n-1];
        
    }
};