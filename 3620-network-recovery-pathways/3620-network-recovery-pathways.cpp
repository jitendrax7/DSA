class Solution {
public:
    bool isValid(vector<vector<pair<int,int>>> & adj, long long & k, int allow ){
        int n = adj.size();
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> result(n,LLONG_MAX);
        pq.push({0,0});
        result[0]  = 0;
        while(!pq.empty()){
            long long cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(result[u]<cost) continue;
            if(cost>k) return false;
            if(u==n-1) return true;
            for(auto & [v,w]: adj[u]){

                if(w<allow) continue;
                if(cost+w<result[v]){
                    result[v] =cost+w;
                    pq.push({cost+w,v});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);

        int st = INT_MAX;
        int end = 0;
        for(auto & edge:edges){
            if(!online[edge[0]] || !online[edge[1]] ) continue;
            st = min(st,edge[2]);
            end = max(end,edge[2]);
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

       int ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;

            if(isValid(adj, k, mid)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }

        return ans;
    }
};