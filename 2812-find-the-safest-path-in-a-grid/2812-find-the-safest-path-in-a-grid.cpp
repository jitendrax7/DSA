//apporch 1 

// here use a multisource bfs , start to a all thief i mean 1 and create a matrix of  distance of nearest thief 
// and then calculate a max dis and use a binary search of dis and use dfs to check its valid or not 


// class Solution {
// public:
//     vector<int> cd = {0,0,1,-1};
//     vector<int> rd = {1,-1,0,0};
//     bool dfs(int & allowd , vector<vector<int>> & matrix,vector<vector<bool>> & vis, int & n, int i, int j ){
//         if(i>=n || j>=n || i<0 || j<0) return false;
//         if (vis[i][j]) return false;
//         if (matrix[i][j] < allowd) return false;

//         if(i==n-1 && j==n-1) return true;
//         vis[i][j] = true;
//         for(int k=0;k<4;k++){
//             if(dfs(allowd,matrix,vis, n, i+rd[k],j+cd[k])) return true;
//         }
//         return false;
//     }
//     bool isValid(int & allowd , vector<vector<int>> & matrix, int n){
//         vector<vector<bool>> vis (n,vector<bool>(n,false));
//         return dfs(allowd ,matrix ,vis ,n, 0,0);
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n = grid.size();

//         if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

//         vector<vector<int>> matrix(n,vector<int>(n,1e9));

//         queue<pair<int,pair<int,int>>> q;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     matrix[i][j] = 0;
//                     q.push({0,{i,j}});
//                 }

//             }
//         }
      
//         while(!q.empty()){
//             auto it  = q.front();
//             q.pop();
//             int step = it.first;
//             int i = it.second.first;
//             int j = it.second.second;

//             for(int k=0;k<4;k++){
//                 int n_i = i+rd[k];
//                 int n_j = j+cd[k];
//                 if(n_i>=n || n_j>=n || n_i<0 ||n_j<0 || grid[n_i][n_j]==1 ) continue;
//                 if(step+1<matrix[n_i][n_j]){
//                     matrix[n_i][n_j] = step+1;
//                     q.push({step+1, {n_i,n_j}});
//                 }
//             }
//         }

//         int end = 0;
//         int st = 1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                end = max(end,matrix[i][j]);
//             }
//         }
//         int ans =0;
//         while(st<=end){

//             int mid = st+(end-st)/2;

//             if(isValid(mid,matrix,n)){
//                 st  = mid+1;
//                 ans = mid;
//             }else{
//                 end = mid-1;
//             }
//         }

//         return ans;
//     }
// };


// apporch 2 //

// here same as first creat a dis matrix but insted or binary search we st from the (0,0) with the Dijkstra's algorithm apply to find the like fisrt sort destance in waighted graph and the weight is a distance  but here use max heap like we need to find the maximam weight weight

class Solution {
public:
    vector<int> cd = {0,0,1,-1};
    vector<int> rd = {1,-1,0,0};
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        vector<vector<int>> matrix(n,vector<int>(n,1e9));   // dist matrix

        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    matrix[i][j] = 0;
                    q.push({0,{i,j}});
                }

            }
        }
      
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int step = it.first;
            int i = it.second.first;
            int j = it.second.second;

            for(int k=0;k<4;k++){
                int n_i = i+rd[k];
                int n_j = j+cd[k];
                if(n_i>=n || n_j>=n || n_i<0 ||n_j<0 || grid[n_i][n_j]==1 ) continue;
                if(step+1<matrix[n_i][n_j]){
                    matrix[n_i][n_j] = step+1;
                    q.push({step+1, {n_i,n_j}});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> vis (n,vector<bool>(n,false));

        pq.push({matrix[0][0],{0,0}});
        vis[0][0] = true;

        while(!pq.empty()){
            int dist = pq.top().first;
            auto [i,j] = pq.top().second;
            pq.pop();
            if(i==n-1 && j==n-1) return dist;

            for(int k=0;k<4;k++){
                int r = i+rd[k];
                int c = j+cd[k];
                if(r>=n || c>=n || r<0 ||c<0 || vis[r][c] || matrix[r][c]==0  ) continue;
                vis[r][c] = true;
                pq.push({min(dist, matrix[r][c]), {r,c}});
            }
        }

        return 0;
    }
};