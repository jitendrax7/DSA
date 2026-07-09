// class DisjointSet {
//     public:
//     vector<int> size, parent;

//     DisjointSet(int n){
//         size.resize(n,1);
//         parent.resize(n);
//         for(int i=0;i<n;i++){
//             parent[i] = i;
//         }
//     }

//     int findUPar(int u){
//         if(u==parent[u]) return u;

//         return parent[u] = findUPar(parent[u]);
//     }

//     void unionBySize(int u, int v){
//         int p_u = findUPar(u);
//         int p_v = findUPar(v);

//         if(p_u==p_v) return;
//         if(size[p_u]<size[p_v]){
//             parent[p_u] = p_v;
//             size[p_v] += size[p_u];
//         }else{
//             parent[p_v] = p_u;
//             size[p_u] += size[p_v];
//         }
//     }
    
// };



// Approach 1: Disjoint Set Union (DSU)
//
// Build connected components using DSU.
// Two indices belong to the same component if there exists a path where
// every adjacent difference is <= maxDiff.
//
// Method 1: Sliding Window
// Since nums is sorted, maintain a valid window [l...r].
// If nums[r] - nums[l] > maxDiff, move l forward.
// Union indices that remain connected inside the valid window.
// Finally, answer each query by checking if both indices have the same
// ultimate parent in the DSU.

// Time Complexity:
// - Building the DSU: O(n * α(n))
// - Answering q queries: O(q * α(n))
// Overall: O((n + q) * α(n))
//
// Space Complexity:
// - Parent array: O(n)
// - Size array: O(n)
// Overall: O(n)

// class Solution {
// public:
    
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
//         DisjointSet ds (n);

//         int l = 0;

//         for(int r =0;r<n;r++){
//             while(l<r && abs(nums[r]-nums[l])>maxDiff) l++;
//             ds.unionBySize(r,l);
//         }

//         while(l<n-1){
//             ds.unionBySize(n-1,l);
//             l++;
//         }

//         vector<bool> ans (queries.size(),false);

//         for(int i =0;i<queries.size();i++){
//             int u = queries[i][0];
//             int v = queries[i][1];

//             ans[i] = ds.findUPar(u)==ds.findUPar(v);
//         }

//         return ans;
//     }
// };


// Approach 1 (Optimized DSU)
//
// Since nums is sorted, we only need to compare adjacent elements.
// If nums[i] - nums[i-1] <= maxDiff,
// then i and i-1 are directly connected, so union them.
//
// Connectivity automatically propagates through the DSU.
//
// Example:
// nums = [1, 3, 5, 9], maxDiff = 2
//
// 1 -- 3 -- 5     9
//
// Queries are answered by checking whether both indices have the same
// ultimate parent.

// Time Complexity:
// - Traverse the array once: O(n)
// - Each union/find operation: O(α(n))
// - Process q queries: O(q * α(n))
// Overall: O((n + q) * α(n))
//
// Space Complexity:
// - Parent array: O(n)
// - Size array: O(n)
// Overall: O(n)


// class Solution {
// public:
    
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
//         DisjointSet ds (n);

//         for(int r =1;r<n;r++){
//             if(nums[r]-nums[r-1] <=maxDiff){
//                 ds.unionBySize(r,r-1);
//             }
//         }

//         vector<bool> ans (queries.size(),false);

//         for(int i =0;i<queries.size();i++){
//             int u = queries[i][0];
//             int v = queries[i][1];

//             ans[i] = ds.findUPar(u)==ds.findUPar(v);
//         }

//         return ans;
//     }
// };



// Approach 2: Grouping (No DSU)
//
// Instead of maintaining a DSU, assign every index to a group.
//
// Traverse the sorted array once.
// - If nums[i] - nums[i-1] <= maxDiff,
//   then nums[i] belongs to the same group.
// - Otherwise, start a new group.
//
// Example:
// nums = [1, 3, 5, 9, 10], maxDiff = 2
//
// Groups:
// [1,3,5]   [9,10]
//
// group = [0,0,0,1,1]
//
// Two indices are connected if and only if they belong to the same group.
//
// Time Complexity: O(n + q)
// Space Complexity: O(n)

class Solution {
public:
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    
        vector<int> group(n);
        int curr = 0;
        for(int i =1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff ){
                curr++;
            }
        
            group[i] = curr;
        }

        vector<bool> ans (queries.size(),false);

        for(int i =0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];

            ans[i] = group[u]==group[v];
        }

        return ans;
    }
};