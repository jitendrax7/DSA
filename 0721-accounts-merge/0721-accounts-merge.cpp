class Solution {
public:

    class Desjointset {
        vector<int> perent, size;
        public:
            Desjointset(int n){
                size.resize(n+1,1);
                perent.resize(n+1);
                for(int i=0;i<=n;i++){
                    perent[i] = i;
                }
            }

            int findUPar(int u){
                if(u==perent[u]) return u;

                return perent[u] = findUPar(perent[u]);
            }

            void unionbysize(int u, int v){
                int up_u = findUPar(u);
                int up_v = findUPar(v);
                if(up_u==up_v) return;

                if(size[up_u]<size[up_v]){
                    perent[up_u] = up_v;
                    size[up_v] += size[up_u];
                }else{
                    perent[up_v] = up_u;
                    size[up_u] += size[up_v];
                }
            }

    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =accounts.size();
        Desjointset ds = Desjointset(n);
       
        unordered_map<string,int> m;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j]) == m.end() ){
                    m[accounts[i][j]] = i;
                }else{
                    ds.unionbysize(i,m[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merge_account (n);
        for(auto it:m){
            merge_account[ds.findUPar(it.second)].push_back(it.first);
        }
    
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merge_account[i].empty()) continue;
            sort(merge_account[i].begin(), merge_account[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto  email : merge_account[i]){
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};