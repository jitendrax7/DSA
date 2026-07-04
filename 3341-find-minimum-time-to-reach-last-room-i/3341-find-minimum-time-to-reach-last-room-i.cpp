class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> times(n,vector<int>(m,INT_MAX));
        times[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int time = pq.top().first;
            auto [r, c] = pq.top().second;
            pq.pop();

            if(time > times[r][c]) continue;

            if(r==n-1 && c==m-1) return time;
            int rd[] ={0,0,1,-1};
            int cd[] ={-1,1,0,0};
            for(int a=0;a<4;a++){
                int newr = r+rd[a];
                int newc = c+cd[a];

                if(newr>=n || newc>=m || newr<0 || newc<0) continue;
            
                int newtime = max(moveTime[newr][newc],time)+1;
                
                if(newtime<times[newr][newc]){
                    pq.push({newtime,{newr,newc}});
                    times[newr][newc] = newtime;
                }
            }
        }

        return times[n-1][m-1];
    }
};