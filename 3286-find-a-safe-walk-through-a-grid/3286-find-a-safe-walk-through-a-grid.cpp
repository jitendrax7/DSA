// approach 1 - use a dijkstra algorithm , its working fine but the time complexity is its O(e*log v)


// class Solution {
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int n = grid.size();
//         int m = grid[0].size();
//         priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
//         vector<vector<int>> dist(n,vector<int>(m,1e9));
//         pq.push({grid[0][0],{0,0}});
//         dist[0][0] = grid[0][0];

//         while(!pq.empty()){
//             int d = pq.top().first;
//             int i = pq.top().second.first;
//             int j = pq.top().second.second;
//             pq.pop();
//             if(i==n-1 && j==m-1){
//                 if(d<health) return true;
//             }
//             int rd[] = {0,0,1,-1};
//             int cd[] = {1,-1,0,0};
//             for(int idx =0;idx<4;idx++){
//                 int r = rd[idx]+i;
//                 int c = cd[idx]+j;
//                 if(r>=n || c>=m || r<0 || c<0) continue;
//                 int newd = d+grid[r][c];
//                 if(newd<dist[r][c]){
//                     pq.push({newd,{r,c}});
//                     dist[r][c] = newd;
//                 }
//             }
//         }

//         return false;
//     }
// };

// this is approach 2 - use a 01 bfs its use same like a dijkstra but insted of using priority queue here use deque because here only two stage , lavel up or the same simple mean dist+0, dist+1 so if dist+0 push in front in same lavel else push in last which is make it sorted in assending order and get the minimum first , 

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1){
                if(d<health) return true;
            }
            int rd[] = {0,0,1,-1};
            int cd[] = {1,-1,0,0};
            for(int idx =0;idx<4;idx++){
                int r = rd[idx]+i;
                int c = cd[idx]+j;
                if(r>=n || c>=m || r<0 || c<0) continue;
                int newd = d+grid[r][c];
                if(newd<dist[r][c]){
                    pq.push({newd,{r,c}});
                    dist[r][c] = newd;
                }
            }
        }

        return false;
    }
};